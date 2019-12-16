from django.http import HttpResponse, Http404
#1 from django.template import loader
from django.shortcuts import render, get_object_or_404 # Using templates in a shortcut way
from .models import Album, Song

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
    # try:
        # album = Album.objects.get(pk=album_id)
    # except Album.DoesNotExist:
        # raise Http404("Album Does not Exists")
    album = get_object_or_404(Album, pk=album_id)
    return render(request, 'music/index1.html', {'album':album})

def favorite(request, album_id):
    album = get_object_or_404(Album, pk=album_id)
    try:
        selected_song = album.song_set.get(pk=request.POST['song'])
    except (KeyError, Song.DoesNotExist):
        return render(request, 'music/index1.html', {
            'album': album,
            'error_message': "You did not select a valid song"
        })
    else:
        selected_song.is_favorite = True
        selected_song.save()
        return render(request, 'music/index1.html', {'album':album})