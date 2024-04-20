import subprocess
from threading import Thread
from os import path, mkdir

if not path.exists("subprojects"):
    mkdir("subprojects")

def get_wrap(wrap):
    subprocess.Popen(["meson", "wrap", "install", wrap]).wait()

wraps = [
    "sfml",
    "flac",
    "freetype2",
    "ogg",
    "openal-soft",
    "vorbis"
]

threads: list[Thread] = []
for wrap in wraps:
    threads.append(Thread(target=get_wrap, args=(wrap,)))
    threads[-1].start()