import kivy
#kivy.require('1.10.0')

from kivy.app import App
from kivy.uix.button import Button
from kivy.uix.label import Label
from kivy.uix.scatter import Scatter
from kivy.uix.floatlayout import FloatLayout

class types_of_button(App):
     def build(self):

	f = FloatLayout()
	s = Scatter()
	b = Button(text="Mine", background_color=(0.987,0.657,0.333,1),font_size=35) 

	f.add_widget(s)
	s.add_widget(b)
	return f

if __name__ == '__main__':
   types_of_button().run()
