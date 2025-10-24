import pygame

pygame.init()
screen = pygame.display.set_mode((500, 400))
pygame.display.set_caption("Pygame Graphics")

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill((255, 255, 255))  # White background
    pygame.draw.circle(screen, (0, 0, 255), (250, 200), 50)  # Blue circle
    pygame.display.flip()

pygame.quit()
