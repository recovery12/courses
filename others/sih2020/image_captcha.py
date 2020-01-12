#!/usr/bin/python3

import numpy as np
import matplotlib.pyplot as plt
from captcha.image import ImageCaptcha

def random_chars() -> str:
    charset = ""
    for i in range(10):
        charset = charset + str(i)

    for i in range(26):
        charset = charset + chr(i+65)
        charset = charset + chr(i+97)

    random_str = ""
    for i in range(7):
        random_str = random_str + np.random.choice(list(charset))

    return random_str

def custom_image_captcha(save: bool=False) -> None:
    image_captcha = ImageCaptcha()

    captcha_text = random_chars()
    image = image_captcha.generate_image(captcha_text)
    # image_captcha.create_noise_curve(image, image.getcolors())

    if save:
        image_captcha.write(chars=captcha_text, output='captcha.png')

    plt.imshow(image)
    plt.show()

    return

if __name__ == '__main__':
    custom_image_captcha(True)