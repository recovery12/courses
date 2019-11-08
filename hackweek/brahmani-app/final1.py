from kivy.app import App
from kivy.lang import Builder
from kivy.uix.screenmanager import ScreenManager, Screen
from kivy.uix.behaviors.button import ButtonBehavior
from kivy.uix.image import Image
from kivy.base import runTouchApp
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.floatlayout import FloatLayout
from kivy.graphics import Color, Rectangle

ca = open('echo1.txt','r')
echo = ca.read().strip()

cb = open('grep1.txt','r')
grep = cb.read().strip()

cc = open('cut1.txt','r')
cut = cc.read().strip()

cd = open('paste1.txt','r')
paste = cd.read().strip()

ce = open('sort1.txt','r')
sort = ce.read().strip()

cf = open('sed1.txt','r')
sed = cf.read().strip()

cg = open('awk1.txt','r')
awk = cg.read().strip()

ib = open('suffix.sh','r')
sufix = ib.read().strip()

ic = open('unsuffix.sh','r')
unsufix = ic.read().strip()

ie = open('greet.sh','r')
greet = ie.read().strip()

ig = open('greetelif.sh','r')
greetelif = ig.read().strip()

ih = open('renameext.sh','r')
renameext = ih.read().strip()

ii = open('num.sh','r')
num = ii.read().strip()

ij = open('filesize.sh','r')
checksize = ij.read().strip()

ik = open('filesize1.sh','r')
bigsize = ik.read().strip()

il = open('pid.sh','r')
pid = il.read().strip()

Builder.load_string("""
<AppScreen>:
    canvas.before:
        RoundedRectangle:
            pos: self.pos
            size: self.size
            source: "1.jpg"
    BoxLayout:
	Image:
	    source: 'first.jpg'
	    on_touch_down: root.manager.current = 'menu'
<MenuScreen>:
    canvas.before:
        RoundedRectangle:
            pos: self.pos
            size: self.size
            source: "apricot.jpg"
    BoxLayout:
        orientation: 'vertical'
        padding: 100
        spacing:10
        Button:
            text: 'Basic Commands'
            font_size: '50sp'
            color: [0.5, 0.18, 0.27, 1]
            size_hint_y: 0.4
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'up'
                root.manager.current = 'commands'
        Button:
            text:'Shell Scripts'
            font_size: '50sp'
            color: [0.5, 0.18, 0.27, 1]
            size_hint_y:0.45
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'up'
                root.manager.current = 'scriptslist'
        Button:
            text: 'Quit'
            font_size: '40sp'
            color: [0.5, 0.18, 0.27, 1]
            size_hint_y: 0.15
            background_color: 251, 206, 177, 0.01
            on_press:
                app.stop()
<ScriptslistScreen>:
    canvas.before:
        RoundedRectangle:
            pos: self.pos
            size: self.size
            source: "3.jpg"
    FloatLayout:
        orientation: 'vertical'
        padding: 100
        spacing: 5
        Button:
            size_hint: 0.3, 0.1
            pos_hint: {"x":0.40, 'y':0.9}
            text: 'Suffix'
            color: [0.44, 0.16, 0.39, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'left'
                root.manager.current = 'suffix'
        Button:
            size_hint: 0.35, 0.1
            pos_hint: {"x":0.028, 'y':0.79}
            text: 'Unsuffix'
            color: [0.44, 0.16, 0.39, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'left'
                root.manager.current = 'unsuffix'
        Button:
            size_hint: 0.4, 0.1
            pos_hint: {"x":0.35, 'y':0.66}
            text: 'Greet'
            color: [0.44, 0.16, 0.39, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'left'
                root.manager.current = 'greet'
        Button:          
            size_hint: 0.4, 0.1
            pos_hint: {"x":0.022, 'y':0.55}
            text: 'Process id'
            color: [0.44, 0.16, 0.39, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'left'
                root.manager.current = 'pid'
        Button:
            size_hint: 0.5, 0.1
            pos_hint: {"x":0.37, 'y':0.43}
            text: 'Rename extension '
            color: [0.44, 0.16, 0.39, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'left'
                root.manager.current = 'renameext'
        Button:           
            size_hint: 0.4, 0.1
            pos_hint: {"x":0.05, 'y':0.31}
            text: 'Print a number '
            color: [0.44, 0.16, 0.39, 1]
            background_color: 251, 206, 177, 0.01
            font_size: '30sp'
            on_press:
                root.manager.transition.direction = 'left'
                root.manager.current = 'number'
        Button:
            size_hint: 0.4, 0.1
            pos_hint: {"x":0.4, 'y':0.18}
            text: 'Check the file size '
            color: [0.44, 0.16, 0.39, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'left'
                root.manager.current = 'filesize'
        Button:
            size_hint: 0.4, 0.1
            pos_hint: {"x":0, 'y':0}
            text: 'Back to menu'
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'right'
                root.manager.current = 'menu'
            color: [0.44, 0.16, 0.39, 1]
<CommandsScreen>:
    canvas.before:
        RoundedRectangle:
            pos: self.pos
            size: self.size
            source: "5.jpg"
    FloatLayout:
        orientation: 'vertical'
        padding: 100
        spacing: 5
        Button:
            size_hint: 0.3, 0.1
            pos_hint: {"x":0.50, 'y':0.9}
            text: ' Echo'
            color: [0.44, 0.16, 0.39, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'left'
                root.manager.current = 'echocommands'
        Button:
            size_hint: 0.35, 0.1
            pos_hint: {"x":0.05, 'y':0.79}
            text: '  Grep'
            color: [0.44, 0.16, 0.39, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'left'
                root.manager.current = 'grepcommands'
        Button:
            size_hint: 0.3, 0.1
            pos_hint: {"x":0.50, 'y':0.66}
            text: 'Cut'
            color: [0.44, 0.16, 0.39, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'left'
                root.manager.current = 'cutcommands'
        Button:          
            size_hint: 0.4, 0.1
            pos_hint: {"x":0.05, 'y':0.55}
            text: 'Paste'
            color: [0.44, 0.16, 0.39, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'left'
                root.manager.current = 'pastecommands'
        Button:
            size_hint: 0.3, 0.1
            pos_hint: {"x":0.50, 'y':0.43}
            text: 'Sort'
            color: [0.44, 0.16, 0.39, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'left'
                root.manager.current = 'sortcommands'
        Button:           
            size_hint: 0.4, 0.1
            pos_hint: {"x":0.05, 'y':0.31}
            text: 'Sed '
            color: [0.44, 0.16, 0.39, 1]
            background_color: 251, 206, 177, 0.01
            font_size: '30sp'
            on_press:
                root.manager.transition.direction = 'left'
                root.manager.current = 'sedcommands'
        Button:
            size_hint: 0.3, 0.1
            pos_hint: {"x":0.50, 'y':0.18}
            text: 'Awk'
            color: [0.44, 0.16, 0.39, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'left'
                root.manager.current = 'awkcommands'
        Button:
            size_hint: 0.4, 0.1
            pos_hint: {"x":0, 'y':0}
            text: 'Back to menu'
            color: [0.44, 0.16, 0.39, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'right'
                root.manager.current = 'menu'
<EchocommandsScreen>:
    canvas.before:
        RoundedRectangle:
            pos: self.pos
            size: self.size
            source: "pink.jpg"
    BoxLayout:
        orientation: 'vertical'
        Label:
            text: '"""+echo+"""'
            font_size: '20sp'
            color: [0.004, 0.26, 0.14, 1]
        Button:
            size_hint: 0.1 , 0.1
            pos_hint: {'center_x': .1, 'center_y': .5}
            text: 'Back'
            color: [0.004, 0.26, 0.14, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'right'
                root.manager.current = 'commands'
<GrepcommandsScreen>:
    canvas.before:
        RoundedRectangle:
            pos: self.pos
            size: self.size
            source: "pink.jpg"
    BoxLayout:
        orientation: 'vertical'
        Label:
            text: '"""+grep+"""'
            font_size: '20sp'
            color: [0.004, 0.26, 0.14, 1]
        Button:
            size_hint: 0.4 , 0.1
            pos_hint: {'center_x': .1, 'center_y': .5}
            text: 'Back'
            color: [0.004, 0.26, 0.14, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'right'
                root.manager.current = 'commands'
<CutcommandsScreen>:
    canvas.before:
        RoundedRectangle:
            pos: self.pos
            size: self.size
            source: "pink.jpg"
    BoxLayout:
        orientation: 'vertical'
        Label:
            text: '"""+cut+"""'
            color: [0.004, 0.26, 0.14, 1]
            font_size: '20sp'
        Button:
            size_hint: 0.4 , 0.1
            pos_hint: {'center_x': .1, 'center_y': .5}
            text: 'Back'
            color: [0.004, 0.26, 0.14, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'right'
                root.manager.current = 'commands'
<PastecommandsScreen>:
    canvas.before:
        RoundedRectangle:
            pos: self.pos
            size: self.size
            source: "pink.jpg"
    BoxLayout:
        orientation: 'vertical'
        Label:
            text: '"""+paste+"""'
            font_size: '20sp'
            color: [0.004, 0.26, 0.14, 1]
        Button:
            size_hint: 0.4 , 0.1
            pos_hint: {'center_x': .1, 'center_y': .5}
            text: 'Back'
            color: [0.004, 0.26, 0.14, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'right'
                root.manager.current = 'commands'
<SortcommandsScreen>:
    canvas.before:
        RoundedRectangle:
            pos: self.pos
            size: self.size
            source: "pink.jpg"
    BoxLayout:
        orientation: 'vertical'
        Label:
            text: '"""+sort+"""'
            font_size: '20sp'
            color: [0.004, 0.26, 0.14, 1]
        Button:
            size_hint: 0.4 , 0.1
            pos_hint: {'center_x': .1, 'center_y': .5}
            text: 'Back'
            font_size: '30sp'
            color: [0.004, 0.26, 0.14, 1]
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'right'
                root.manager.current = 'commands'
<SedcommandsScreen>:
    canvas.before:
        RoundedRectangle:
            pos: self.pos
            size: self.size
            source: "pink.jpg"
    BoxLayout:
        orientation: 'vertical'
        Label:
            text: '"""+sed+"""'
            font_size: '20sp'
            color: [0.004, 0.26, 0.14, 1]
        Button:
            size_hint: 0.4 , 0.1
            pos_hint: {'center_x': .1, 'center_y': .5}
            text: 'Back'
            font_size: '30sp'
            color: [0.004, 0.26, 0.14, 1]
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'right'
                root.manager.current = 'commands'
<AwkcommandsScreen>:
    canvas.before:
        RoundedRectangle:
            pos: self.pos
            size: self.size
            source: "pink.jpg"
    BoxLayout:
        orientation: 'vertical'
        Label:
            text: '"""+awk+"""'
            font_size: '20sp'
            color: [0.004, 0.26, 0.14, 1]
        Button:
            size_hint: 0.4 , 0.1
            pos_hint: {'center_x': .1, 'center_y': .5}
            text: 'Back'
            color: [0.004, 0.26, 0.14, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'right'
                root.manager.current = 'commands'
<SuffixScreen>:
    canvas.before:
        RoundedRectangle:
            pos: self.pos
            size: self.size
            source: "green.jpg"
    BoxLayout:
        orientation: 'vertical'
        Label:
            text: '"""+sufix+"""'
            color: [0.11, 0.30, 0.24, 1]
            font_size: '30sp'
        Button:
            size_hint: 0.4 , 0.1
            pos_hint: {'center_x': .1, 'center_y': .5}
            text: 'Back'
            color: [0.11, 0.30, 0.24, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'right' 
                root.manager.current = 'scriptslist'
<UnsuffixScreen>:
    canvas.before:
        RoundedRectangle:
            pos: self.pos
            size: self.size
            source: "green.jpg"
    BoxLayout:
        orientation: 'vertical'
        Label:
            size_hint_y: 0.9
            text:'"""+unsufix+"""'
            font_size: '25sp'
            color: [0.11, 0.30, 0.24, 1]
        Button:
            size_hint: 0.4 , 0.1
            pos_hint: {'center_x': .1, 'center_y': .5}
            text:'Back'
            color: [0.11, 0.30, 0.24, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'right'
                root.manager.current = 'scriptslist'
<PidScreen>:
    canvas.before:
        RoundedRectangle:
            pos: self.pos
            size: self.size
            source: "green.jpg"
    BoxLayout:
        orientation: 'vertical'
        Label:
            size_hint_y: 0.9
            text:'"""+pid+"""'
            font_size: '18sp'
            color: [0.11, 0.30, 0.24, 1]
        Button:
            size_hint: 0.4 , 0.1
            pos_hint: {'center_x': .1, 'center_y': .5}
            text:'Back'
            color: [0.11, 0.30, 0.24, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'right'
                root.manager.current = 'scriptslist'
<GreetScreen>:
    canvas.before:
        RoundedRectangle:
            pos: self.pos
            size: self.size
            source: "violet.jpg"
    BoxLayout:
        orientation: 'vertical'
        padding: 10
        scaling: 15
        Button:
            size_hint_y: 0.45
            text: 'Greet using if '
            color: [0, 0, 0, 1]
            font_size: '35sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'left'
                root.manager.current = 'greetif'
        Button:
            size_hint_y: 0.45
            text: 'Greet using elif'
            color: [0, 0, 0, 1]
            font_size: '35sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'left'
                root.manager.current = 'greetelif'
        Button:
            size_hint: 0.4 , 0.1
            pos_hint: {'center_x': .1, 'center_y': .5}
            text:'Back'
            color: [0, 0, 0, 1]
            font_size: '35sp'
            background_color: 251, 206, 177, 0.2
            on_press:
                root.manager.transition.direction = 'right' 
                root.manager.current = 'scriptslist'

<GreetifScreen>:
    canvas.before:
        RoundedRectangle:
            pos: self.pos
            size: self.size
            source: "green.jpg"
    BoxLayout:
        orientation: 'vertical'
        Label:
            size_hint_y: 0.9
            text:'"""+greet+"""'
            color: [0.11, 0.30, 0.24, 1]
            font_size: '20sp'
        Button:
            size_hint: 0.4 , 0.1
            pos_hint: {'center_x': .1, 'center_y': .5}
            text:'Back'
            color: [0.11, 0.30, 0.24, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'right'
                root.manager.current = 'greet'
<GreetelifScreen>:
    canvas.before:
        RoundedRectangle:
            pos: self.pos
            size: self.size
            source: "green.jpg"
    BoxLayout:
        orientation: 'vertical'
        Label:
            size_hint_y: 0.9
            text:'"""+greetelif+"""'
            color: [0.11, 0.30, 0.24, 1]
            font_size: '20sp'
        Button:
            size_hint: 0.4 , 0.1
            pos_hint: {'center_x': .1, 'center_y': .5}
            text:'Back'
            color: [0.11, 0.30, 0.24, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'right'
                root.manager.current = 'greet'
<RenameextScreen>:
    canvas.before:
        RoundedRectangle:
            pos: self.pos
            size: self.size
            source: "green.jpg"
    BoxLayout:
        orientation: 'vertical'
        Label:
            size_hint_y: 0.9
            text:'"""+renameext+"""'
            color: [0.11, 0.30, 0.24, 1]
            font_size: '20sp'
        Button:
            size_hint: 0.4 , 0.1
            pos_hint: {'center_x': .1, 'center_y': .5}
            text:'Back'
            color: [0.11, 0.30, 0.24, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'right' 
                root.manager.current = 'scriptslist'
<NumberScreen>:
    canvas.before:
        RoundedRectangle:
            pos: self.pos
            size: self.size
            source: "green.jpg"
    BoxLayout:
        orientation: 'vertical'
        Label:
            size_hint_y: 0.9
            text:'"""+num+"""'
            color: [0.11, 0.30, 0.24, 1]
            font_size: '20sp'
        Button:
            size_hint: 0.4 , 0.1
            pos_hint: {'center_x': .1, 'center_y': .5}
            text:'Back'
            color: [0.11, 0.30, 0.24, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'right'
                root.manager.current = 'scriptslist'
<FilesizeScreen>:
    canvas.before:
        RoundedRectangle:
            pos: self.pos
            size: self.size
            source: "violet.jpg"
    BoxLayout:
        orientation: 'vertical'
        padding: 10
        scaling: 15
        Button:
            size_hint_y: 0.45
            text: 'To check file size '
            color: [0, 0, 0, 1]
            font_size: '35sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'left'
                root.manager.current = 'checksize'
        Button:
            size_hint_y: 0.45
            text: 'To list files which are bigger than a given value'
            color: [0, 0, 0, 1]
            font_size: '33sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'left'
                root.manager.current = 'listbigsize'
        Button:
            size_hint: 0.4 , 0.1
            pos_hint: {'center_x': .1, 'center_y': .5}
            text:'Back'
            color: [0, 0, 0, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'right'
                root.manager.current = 'scriptslist'

<ChecksizeScreen>:
    canvas.before:
        RoundedRectangle:
            pos: self.pos
            size: self.size
            source: "green.jpg"
    BoxLayout:
        orientation: 'vertical'
        Label:
            size_hint_y: 0.9
            text: '"""+checksize+"""'
            color: [0.11, 0.30, 0.24, 1]
            font_size: '20sp'
        Button:
            size_hint: 0.4 , 0.1
            pos_hint: {'center_x': .1, 'center_y': .5}
            text: 'Back'
            color: [0.11, 0.30, 0.24, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'right' 
                root.manager.current = 'filesize'
<ListbigsizeScreen>:
    canvas.before:
        RoundedRectangle:
            pos: self.pos
            size: self.size
            source: "green.jpg"
    BoxLayout:
        orientation: 'vertical'
        Label:
            size_hint_y: 0.9
            text: '"""+bigsize+"""'
            color: [0.11, 0.30, 0.24, 1]
            font_size: '20sp'
        Button:
            size_hint: 0.4 , 0.1
            pos_hint: {'center_x': .1, 'center_y': .5}
            text: 'Back'
            color: [0.11, 0.30, 0.24, 1]
            font_size: '30sp'
            background_color: 251, 206, 177, 0.01
            on_press:
                root.manager.transition.direction = 'right'
                root.manager.current = 'filesize'
""")

class AppScreen(Screen):
    pass

class MenuScreen(Screen):
    pass

class CommandsScreen(Screen):
    pass

class ScriptslistScreen(Screen):
    pass

class EchocommandsScreen(Screen):
    pass
class GrepcommandsScreen(Screen):
    pass
class CutcommandsScreen(Screen):
    pass
class PastecommandsScreen(Screen):
    pass
class SortcommandsScreen(Screen):
    pass
class SedcommandsScreen(Screen):
    pass
class AwkcommandsScreen(Screen):
    pass
class SuffixScreen(Screen):
    pass
class UnsuffixScreen(Screen):
    pass
class PidScreen(Screen):
    pass
class GreetScreen(Screen):
    pass
class GreetifScreen(Screen):
    pass
class GreetelifScreen(Screen):
    pass
class RenameextScreen(Screen):
    pass
class NumberScreen(Screen):
    pass
class FilesizeScreen(Screen):
    pass
class ChecksizeScreen(Screen):
    pass
class ListbigsizeScreen(Screen):
    pass
sm = ScreenManager()
sm.add_widget(AppScreen(name='app'))
sm.add_widget(MenuScreen(name='menu'))
sm.add_widget(CommandsScreen(name='commands'))
sm.add_widget(ScriptslistScreen(name='scriptslist'))
sm.add_widget(EchocommandsScreen(name='echocommands'))
sm.add_widget(GrepcommandsScreen(name='grepcommands'))
sm.add_widget(CutcommandsScreen(name='cutcommands'))
sm.add_widget(PastecommandsScreen(name='pastecommands'))
sm.add_widget(SortcommandsScreen(name='sortcommands'))
sm.add_widget(SedcommandsScreen(name='sedcommands'))
sm.add_widget(AwkcommandsScreen(name='awkcommands'))
sm.add_widget(SuffixScreen(name='suffix'))
sm.add_widget(UnsuffixScreen(name='unsuffix'))
sm.add_widget(PidScreen(name='pid'))
sm.add_widget(GreetScreen(name='greet'))
sm.add_widget(GreetifScreen(name='greetif'))
sm.add_widget(GreetelifScreen(name='greetelif'))
sm.add_widget(RenameextScreen(name='renameext'))
sm.add_widget(NumberScreen(name='number'))
sm.add_widget(FilesizeScreen(name='filesize'))
sm.add_widget(ChecksizeScreen(name='checksize'))
sm.add_widget(ListbigsizeScreen(name='listbigsize'))
ca.close()
cb.close()
cc.close()
cd.close()
ce.close()
cf.close()
cg.close()
ib.close()
ic.close()
ie.close()
ig.close()
ih.close()
ii.close()
ij.close()
il.close()
class ScriptApp(App):
    def build(self):
        return sm
              
if __name__ == '__main__':
    ScriptApp().run()

