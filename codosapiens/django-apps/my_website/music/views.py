from django.http import HttpResponse
from django.template import loader
from .models import Album

def index(request):
    html = ''
    return HttpResponse(html)

# def index(request):
#     all_album = Album.objects.all()
#     html = ''
#     for album in all_album:
#         url = '/music/'+str(album.id)+'/'
#         html += '<a href="'+url+'"> '+album.artist+' </a><br>'
#     return HttpResponse(html)

def index1(request, album_id):
    return HttpResponse("<h2> This is View "+ str(album_id) +" Taylor </h2>")
