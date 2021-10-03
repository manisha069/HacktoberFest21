# copyright Aman-Verma-28

documentation = """
    This project deals with automating the dino game which we play in chrome in offline mode
    You will need to adjust the height and width according to your screen size
    After that turn off your PC's wifi and run this script and you will see that the game is automatically being played by this script
"""

requirement = """
    pip install pyautogui
    pip install PIL
"""

# --------------------------------------------   CODE    --------------------------------------------------

import pyautogui
from PIL import Image, ImageGrab
import time


def hit(key):
    pyautogui.keyDown(key)
    return


def collide(data):
    for i in range(600, 650):
        for j in range(420, 480):
            if data[i, j] < 170:
                hit("up")
                return

    for i in range(600, 650):
        for j in range(300, 400):
            if data[i, j] < 170:
                hit("down")
                return
    return


if __name__ == "__main__":
    print("start")
    time.sleep(5)
    print("now")
    hit("up")
    while True:
        image = ImageGrab.grab().convert('L')
        data = image.load()
        collide(data)


