from django.http import HttpResponse, Http404
#1 from django.template import loader
from django.shortcuts import render # Using templates in a shortcut way
from .models import Album

# Write a template in a shortcut way
def index(request):
    all_albums = Album.objects.all()
    context = {'all_albums':all_albums}
    return render(request, 'music/index.html', context)

#1 def index(request):
#     all_albums = Album.objects.all()
#     template = loader.get_template('music/index.html')
#     html = ''
#     context = {
#         'all_albums':all_albums,
#     }
#     return HttpResponse(template.render(context, request))

# def index(request):
#     all_album = Album.objects.all()
#     html = ''
#     for album in all_album:
#         url = '/music/'+str(album.id)+'/'
#         html += '<a href="'+url+'"> '+album.artist+' </a><br>'
#     return HttpResponse(html)

def index1(request, album_id):
    try:
        album = Album.objects.get(pk=album_id)
    except Album.DoesNotExist:
        raise Http404("Album Does not Exists")
    return render(request, 'music/index1.html', {'album':album})
