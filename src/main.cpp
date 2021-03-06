#include "MainWindow.h"

#include <QApplication>
#include <QCommandLineParser>
#include <QDir>


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QApplication::setApplicationName(QStringLiteral("CuteNodes"));
    QApplication::setApplicationVersion(QStringLiteral("0.1"));

    QCommandLineParser parser;
    parser.setApplicationDescription(QStringLiteral("Node Editor based on the Qt Graphics View Framework"));
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("scene",
        QCoreApplication::translate("main", "Scene file to load on start [json]"), "[scene]");

    parser.process(app);

    const auto posArgs = parser.positionalArguments();
    const auto sceneFileName = posArgs.isEmpty() ? QString() : posArgs.first();

    // go one level up from bin directory, this will be the root directory for the project
    QDir::setCurrent("..");

    MainWindow window{sceneFileName};
    window.show();

    return app.exec();
}
