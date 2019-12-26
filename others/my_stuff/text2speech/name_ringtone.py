#!/usr/bin/python3

from gtts import gTTS

def name_ringtone(name: str) -> None:
    mytext = name + " please pick up the phone"
    # mytext = "శిరీష మానే ప్లీజ్ పికప్ ద ఫోన్"
    language = "te"

    ringtone = gTTS(text=mytext, lang=language, slow=False)
    ringtone.save(name+"_ringtone.mp3")
    print("Your mp4 file name is", name+"_ringtone.mp3")

    return

if __name__ == '__main__':
    name = input("Enter your name: ")

    name_ringtone(name)
