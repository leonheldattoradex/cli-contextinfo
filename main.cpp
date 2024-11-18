#include <QGuiApplication>
#include <QOpenGLContext>
#include <QOffscreenSurface>
#include <QDebug>
#include <QSurfaceFormat>

int main(int argc, char **argv) {
    QGuiApplication app(argc, argv);

    QSurfaceFormat format;
    format.setVersion(4, 5); // GL 4.5, probably need to change this for GLES
    format.setProfile(QSurfaceFormat::CoreProfile);

    QOpenGLContext context;
    context.setFormat(format);

    if (!context.create()) {
        qCritical() << "Heilige scheisse!!! We failed to create an OpenGL context";
        return -1;
    }

    QOffscreenSurface surface;
    surface.setFormat(format);
    surface.create();

    if (!surface.isValid()) {
        qCritical() << "Oh Meu Deus!!! We failed to create an offscreen surface";
        return -1;
    }

    if (!context.makeCurrent(&surface)) {
        qCritical() << "Mamma Mia!!! We failed to make OpenGL context the current";
        return -1;
    }

    qDebug() << "OpenGL Version:" << reinterpret_cast<const char *>(glGetString(GL_VERSION));
    qDebug() << "OpenGL Renderer:" << reinterpret_cast<const char *>(glGetString(GL_RENDERER));
    qDebug() << "OpenGL Vendor:" << reinterpret_cast<const char *>(glGetString(GL_VENDOR));

    return 0;
}
