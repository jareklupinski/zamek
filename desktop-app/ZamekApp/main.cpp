#include "zamekapp.h"
#include <QApplication>

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );
    ZamekApp w;
    w.show();

    return a.exec();
}
