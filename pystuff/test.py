import pygame
import sys

# Initialize Pygame
pygame.init()

# Set up the display
width, height = 600, 400
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Pygame Test Window")

# --- Main Game Loop ---
running = True
x = width // 2
y = height // 2
radius = 50
dx = 2
dy = 2

while running:
    # Check for events (like closing the window)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
            
    # Fill the screen with a color (light yellow)
    screen.fill((255, 255, 179))

    # Draw the ball
    pygame.draw.circle(screen, (0, 0, 255), (x, y), radius)
    
    # Control frame rate
    pygame.time.delay(10)

    # Update the display
    pygame.display.flip()

# Quit Pygame
pygame.quit()
sys.exit()
