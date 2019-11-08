import kivy
kivy.require('1.0.3')

from kivy.app import App
from kivy.uix.widget import Widget
from kivy.uix.button import Button
from kivy.uix.screenmanager import ScreenManager, Screen
from kivy.uix.label import Label
from kivy.vector import Vector
from kivy.clock import Clock
from random import randint,random
from kivy.graphics.instructions import Canvas
from kivy.properties import NumericProperty,ObjectProperty,ReferenceListProperty
from kivy.uix.boxlayout import BoxLayout



class PongGame(Widget):
    playstatus=NumericProperty(0)
    ball=ObjectProperty(None)
    player1=ObjectProperty(None)
    player2=ObjectProperty(None)

    def initializer(self):
        self.player1.score=0
        self.player2.score=0
        self.player1.center_y=self.center_y
        self.player2.center_y=self.center_y


    def serveball(self,vel=(4,0)):
        self.ball.center=self.center
        self.ball.velocity=vel

    def on_touch_down(self,touch):
        if self.playstatus is 1:
            pass
        else:
            self.playstatus=1
            self.parent.startgame()

    def on_touch_move(self,touch):
		if touch.x<self.width/3:
			self.player1.center_y=touch.y
		if touch.x>self.width-self.width/3:
			self.player2.center_y=touch.y

    def update(self,dt):
            self.ball.move()
            self.player1.bounce_ball(self.ball)
            self.player2.bounce_ball(self.ball)

            if(self.ball.y<0) or (self.ball.top>self.height):
	               self.ball.velocity_y *=-1

            if self.ball.x<self.x:
                self.player2.score+=1
                self.serveball(vel=(4,0))

            if self.ball.x>self.width:
                self.player1.score+=1
                self.serveball(vel=(-4,0))

            if self.player1.score is 5:
                self.playstatus=0
                self.parent.end1game()
                self.initializer()
                return False


            if self.player2.score is 5:
                self.playstatus=0
                self.parent.end2game()
                self.initializer()
                return False


class PongBall(Widget):
	velocity_x=NumericProperty(0)
	velocity_y=NumericProperty(0)
	velocity=ReferenceListProperty(velocity_x,velocity_y)
	def move(self):
		self.pos=Vector(*self.velocity)+self.pos


class PongPaddle(Widget):
	score=NumericProperty(0)

	def bounce_ball(self,ball):
		if self.collide_widget(ball):
			vx,vy=ball.velocity
			offset=(ball.center_y-self.center_y)/(self.height/2)
			bounced=Vector(-1*vx,vy)
			if abs(vx)<25:
				vel=bounced*1.2
			else:
				vel=bounced
			ball.velocity=vel.x,vel.y+offset


#class MainFrame(Widget):
#    scmn=ObjectProperty(None)
#    game=ObjectProperty(None)

#    def menustart(self):
#        self.scmn.start()
#        return self.scmn
#    def gamestart(self):
#        pass
#       #self.game.serveball()
#        #Clock.schedule_interval(self.game.update,1.0/60.0)
class MenuScreen(Screen):
    pass

class SettingsScreen(Screen):
    pass

class MultiplayerScreen(Screen):
    pass

class HostScreen(Screen):
    pass

class ClientScreen(Screen):
    pass

class ClientConnectedScreen(Screen):
    pass

class ClientGameScreen(Screen):
    pass

class HostGameScreen(Screen):
    pass

class AboutScreen(Screen):
    pass

class SameDeviceScreen(Screen):
    #game=ObjectProperty(None)
    #game=PongGame()
    game=ObjectProperty(None)

    def go_main_menu(self):
        self.manager.transition.direction='down'
        self.manager.current = 'menu'


    def startgame(self):
        self.game.serveball()
        Clock.schedule_interval(self.game.update,1.0/60.0)
        return self.game

    def end1game(self):
        #self.manager.transition.direction='down'
        self.manager.current = 'p1win'


    def end2game(self):
        self.manager.current = 'p2win'

class P1WinsScreen(Screen):
    pass

class P2WinsScreen(Screen):
    pass

class ScM(ScreenManager):
        def start(self):
            self.add_widget(MenuScreen(name='menu'))
            self.add_widget(AboutScreen(name='about'))
            self.add_widget(SettingsScreen(name='settings'))
            self.add_widget(MultiplayerScreen(name='multi'))
            self.add_widget(HostScreen(name='host'))
            self.add_widget(ClientScreen(name='client'))
            self.add_widget(ClientConnectedScreen(name='clientconnect'))
            self.add_widget(ClientGameScreen(name='clientgame'))
            self.add_widget(HostGameScreen(name='hostgame'))
            self.add_widget(SameDeviceScreen(name='samegame'))
            self.add_widget(P1WinsScreen(name='p1win'))
            self.add_widget(P2WinsScreen(name='p2win'))



class GameApp(App):
    def build(self):
        #mf=MainFrame()
        #mf.menustart()
        sm=ScM()
        sm.start()
        return sm

if __name__=='__main__':
    GameApp().run()
