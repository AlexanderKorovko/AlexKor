#ifndef FILTER_H
#define FILTER_H



#include <QFile>
#include <QString>
#include <QDebug>
#include <QThread>


class filter : public QThread
{
public:
    filter(QString input_path, QString output_path, int pow);
    void run();
    QString input;
    QString output;

private:
    int this_pow;
    double gauss(int color, float sigma);
};

#endif // FILTER_H
