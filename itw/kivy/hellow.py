import kivy
kivy.require('1.10.0')

from kivy.app import App
from kivy.uix.label import Label

class helloApp(App):

    def build(self):
	return Label(text='hello world!')

if __name__ == '__main__':
	helloApp().run()
