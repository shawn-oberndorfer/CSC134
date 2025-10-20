import pygame
import sys
import math
import random

# Initialize Pygame
pygame.init()

# Set up the display
width, height = 700, 600
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Four Balls with Collision Stars")

clock = pygame.time.Clock()

# --- Ball Class ---
class Ball:
    def __init__(self, x, y, dx, dy, radius, color):
        self.x = x
        self.y = y
        self.dx = dx
        self.dy = dy
        self.radius = radius
        self.color = color

    def move(self):
        self.x += self.dx
        self.y += self.dy

        corner_hit = False

        # Bounce off walls
        if self.x - self.radius <= 0 or self.x + self.radius >= width:
            self.dx = -self.dx
            if self.y - self.radius <= 0 or self.y + self.radius >= height:
                corner_hit = True

        if self.y - self.radius <= 0 or self.y + self.radius >= height:
            self.dy = -self.dy
            if self.x - self.radius <= 0 or self.x + self.radius >= width:
                corner_hit = True

        return corner_hit

    def draw(self, surface):
        pygame.draw.circle(surface, self.color, (int(self.x), int(self.y)), self.radius)

# --- Star Drawing ---
def draw_star(surface, x, y, size, color):
    """Draw a ✦ sparkle"""
    pygame.draw.line(surface, color, (x - size, y), (x + size, y), 2)
    pygame.draw.line(surface, color, (x, y - size), (x, y + size), 2)
    pygame.draw.line(surface, color, (x - size, y - size), (x + size, y + size), 2)
    pygame.draw.line(surface, color, (x - size, y + size), (x + size, y - size), 2)

# --- Star Spawning ---
# Store stars as (x, y, dx, dy, lifetime, size)
stars = []

def spawn_stars(cx, cy, count=10, distance=0, speed=3, size=8, lifetime=30):
    """Spawn stars with outward velocity"""
    for _ in range(count):
        angle = random.uniform(0, 2 * math.pi)
        sx = cx + math.cos(angle) * distance
        sy = cy + math.sin(angle) * distance
        dx = math.cos(angle) * random.uniform(1, speed)
        dy = math.sin(angle) * random.uniform(1, speed)
        stars.append([sx, sy, dx, dy, lifetime, size])

# --- Create Four Balls ---
balls = [
    Ball(150, 200, 3, 2, 40, (0, 0, 255)),    # blue
    Ball(450, 200, -2, -3, 40, (255, 0, 0)),  # red
    Ball(300, 100, 2, 3, 30, (0, 200, 0)),    # green
    Ball(300, 300, -3, 2, 35, (200, 0, 200))  # purple
]

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Move balls and check for corner hits
    for ball in balls:
        if ball.move():
            spawn_stars(ball.x, ball.y, count=8, distance=ball.radius+10, speed=4)

    # --- Ball Collision Detection (check every pair) ---
    for i in range(len(balls)):
        for j in range(i+1, len(balls)):
            b1, b2 = balls[i], balls[j]
            dx = b1.x - b2.x
            dy = b1.y - b2.y
            distance = math.hypot(dx, dy)

            if distance <= b1.radius + b2.radius:
                # Swap velocities (simple elastic collision)
                b1.dx, b2.dx = b2.dx, b1.dx
                b1.dy, b2.dy = b2.dy, b1.dy

                # Push apart slightly
                overlap = (b1.radius + b2.radius) - distance
                angle = math.atan2(dy, dx)
                b1.x += math.cos(angle) * (overlap / 2)
                b1.y += math.sin(angle) * (overlap / 2)
                b2.x -= math.cos(angle) * (overlap / 2)
                b2.y -= math.sin(angle) * (overlap / 2)

                # Spawn impact stars at collision point
                cx = (b1.x + b2.x) / 2
                cy = (b1.y + b2.y) / 2
                spawn_stars(cx, cy, count=15, distance=0, speed=5, size=10, lifetime=25)

    # --- Update Stars ---
    for star in stars:
        star[0] += star[2]  # move x
        star[1] += star[3]  # move y
        star[4] -= 1        # decrease lifetime
        star[5] = max(2, star[5] - 0.15)  # shrink
    stars = [s for s in stars if s[4] > 0]

    # --- Draw Everything ---
    screen.fill((0, 0, 0))
    for ball in balls:
        ball.draw(screen)

    for sx, sy, _, _, life, size in stars:
        alpha = max(50, life * 8)
        color = (255, 255, alpha)
        draw_star(screen, int(sx), int(sy), int(size), color)

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
sys.exit()
