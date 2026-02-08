#include <QCoreApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <NandinaUI/Nandina/Components/component_registrar.hpp>

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

    Nandina::Components::registerAllComponents();

  QQmlApplicationEngine engine;
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreationFailed, &app,
      []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);
  engine.loadFromModule("rainer_blog_dashboard", "Main");

  return app.exec();
}
