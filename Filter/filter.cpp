#include "filter.h"

filter::filter(QString input_path, QString output_path, int pow)
{    
    input = input_path;
    output = output_path;
    this_pow = pow;
}

void filter::run()
{
    QStringList list = input.split(',');
    QString str;
    foreach(str, list)
    {
        QFile file_input(str);
        QStringList list_out = str.split('/');
        list_out[list_out.length() -1].truncate(list_out[list_out.length() -1].length() -4);
        QString name = list_out[list_out.length() -1];
        //QFile file_output(output + "/" + name + "_filtered.txt");
        QFile file_output(output + "/_filtered.txt");

        if(!file_input.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Ошибка открытия файла!";
        }

//        if(!file_output.open(QIODevice::WriteOnly | QIODevice::Text))
//        {
//            qDebug() << "Ошибка открытия файла!";
//        }

        if(!file_output.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append))
        {
            qDebug() << "Ошибка открытия файла!";
        }

        while (!file_input.atEnd())
        {
            QString line = QString::fromLocal8Bit(file_input.readLine());
            QStringList list = line.split(" ");
            int mean_color = (list.at(3).toInt() + list.at(4).toInt() + list.at(5).toInt())/3;
            if(rand() < RAND_MAX/this_pow*gauss(mean_color, 600))
            {
               file_output.write(line.toLocal8Bit());
            }
        }
        file_output.close();
        file_input.close();
    }
}

double filter::gauss(int color, float sigma)
{
    int mean = 255;
    return pow(M_E,(-pow(color-mean, 2)/(2*sigma*sigma)));
}
