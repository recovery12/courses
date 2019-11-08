import kivy

from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.button import Button

class RootWidget(BoxLayout):
    def __init__(self, **kwargs):
        super(RootWidget, self).__init__(**kwargs)
        self.add_widget(
	Button(
		text='Mine',
		size_hint= (1, 1)))
class Button(App):
    def build(self):
        self.root = root = RootWidget()
        root.bind(size=self._update_rect, pos=self._update_rect)

	return root

    def _update_rect(self, instance, value):
	self.rect.pos = instance.pos
	self.rect.size = instance.size

if __name__ == '__main__':
   Button().run()
