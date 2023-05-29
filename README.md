# copy-constructor-demonstration
A simple demonstration for Copy Constructors (OOP) written in C++ and Python. Streamlit web UI available.

## How to use?

### First make sure you installed PIPENV

Create python environment

```bash
pipenv install --ignore-pipfile
```
### Compile libapp file

```bash
g++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` bindings.cpp -o libapp$(python3-config --extension-suffix
```

### Streamlit

```bash
streamlit run streamlit_app.py
