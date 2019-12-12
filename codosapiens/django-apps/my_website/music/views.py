from django.http import HttpResponse
from .models import Album

def index(request):
    return HttpResponse("<h1> This is a music app </h1>")

def index1(request, album_id):
    return HttpResponse("<h2> This is View "+ str(album_id) +" Taylor </h2>")
