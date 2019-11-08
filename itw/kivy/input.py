import kivy
#kivy.require('1.10.0')

from kivy.app import App
from kivy.uix.widget import Widget

class Touch(Widget):
    def on_touch_down(self, touch):
	print(touch)
    def on_touch_move(self, touch):
	print(touch)
    def on_touch_up(self, touch):
	print("Released",touch)

class Inputtouch(App):
     def build(self):
      return Touch()

if __name__ == '__main__':
   Inputtouch().run()
