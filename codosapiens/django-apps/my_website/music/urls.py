from django.urls import path
from . import views

app_name = 'music'

urlpatterns = [
    path('<int:album_id>/', views.index1, name='index1'),
    path('', views.index, name='index'),
]