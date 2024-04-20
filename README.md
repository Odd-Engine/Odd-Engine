# Pre-build
* Set up a python virtual environment (`python -m venv venv`) (`venv` is already in `.gitignore`)

* Activate the virtual environment (`.\venv\Scripts\activate` on Windows, `source venv/bin/activate` in bash)

* Install dependencies (`pip install -r requirements.txt`)

* Set up pre-commit (`pre-commit install`)

# Build instructions
```cmd
meson setup build
meson compile -C build
```
exectuble is build/main