#include <QCoreApplication>
#include <QSettings>
#include "windows.h"

void setDesktopImage();//定义在main函数下面

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    setDesktopImage();
    return a.exec();
}

void setDesktopImage()
{
    //壁纸注册表表
    QSettings wallPaper("HKEY_CURRENT_USER\\Control Panel\\Desktop",
                        QSettings::NativeFormat);

    //新的桌面图片路径
    QString path("C:/ProgramData/Epic/EpicGamesLauncher/Data/EMS/EpicGamesLauncher/RC_Background.png");

    //给壁纸注册表设置新的值（新的图片路径）
    wallPaper.setValue("Wallpaper",path);
    QByteArray byte = path.toLocal8Bit();

    //调用windowsAPI
    SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, byte.data(), SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE);

}
