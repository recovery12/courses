
import pyttsx3 as tts

"""
    ### Installation ###
    -> Ubuntu
       pip3 install pyttsx3 (without internet)
"""

def speak(message, vol, rate=120):
    eng = tts.init()
    eng.say(message)
    eng.setProperty("volume", vol)
    eng.setProperty("rate", rate)
    eng.runAndWait()

if __name__ == '__main__':
    message = input("Enter message: ")
    vol = float(input("Enter vol [0.0, 1.0]: "))
    speak(message, vol)
