#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QPixmap>
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>

class ImageButton: public QPushButton
{
  Q_OBJECT
public:
    ImageButton() = default;
    ImageButton(QWidget* parent);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent* e) override;

public slots:
    void setUp();
    void setDown();

private:
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonDownPixmap;
    QPixmap mButtonUpPixmap;
    bool isDown = false;
};

ImageButton::ImageButton(QWidget* parent)
{
    setParent(parent);
    setToolTip("Stop");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    mButtonUpPixmap(QPixmap("C:\\"));
    mButtonDownPixmap(QPixmap("C:\\"));
    mCurrentButtonPixmap = mButtonUpPixmap;
    setGeometry(mCurrentButtonPixmap.rect());
    connect(this, &QPushButton::clicked, this, &ImageButton::setDown);
}

void ImageButton::paintEvent(QPaintEvent *e)
{
     QPainter p(this);
     p.drawPixmap(e->rect(), mCurrentButtonPixmap);
}

QSize ImageButton::sizeHint() const
{
    return QSize(100, 100);
}

QSize ImageButton::minimumSizeHint() const
{
    return sizeHint();
}

void ImageButton::keyPressEvent(QKeyEvent *e)
{
    setDown();
}

void ImageButton::setDown()
{
    mCurrentButtonPixmap = mButtonDownPixmap;
    update();
    QTimer::singleShot(100, this, &ImageButton::setUp);
}

void ImageButton::setUp()
{
    mCurrentButtonPixmap = mButtonUpPixmap;
    update();
}


int main(int argc, char** argv) {QApplication app(argc, argv);
  ImageButton redButton(nullptr);
  redButton.setFixedSize(100, 100);
  redButton.move(1000, 400);
  QObject::connect(&redButton, &QPushButton::clicked, []() {std::cout << "clicked\n";});
  redButton.show();
  return app.exec();

}
