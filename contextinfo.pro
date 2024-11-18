TEMPLATE = app
QT += widgets opengl
requires(qtConfig(filedialog))

SOURCES += main.cpp 

# install
target.path = $$[QT_INSTALL_EXAMPLES]/opengl/contextinfo
INSTALLS += target
