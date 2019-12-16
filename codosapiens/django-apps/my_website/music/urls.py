from django.urls import path
from . import views

app_name = 'music'

urlpatterns = [
    path('', views.index, name='index'),
    path('<int:album_id>/', views.index1, name='index1'),
    path('<int:album_id>/favorite/', views.favorite, name='favorite'),
]