#pragma once

#include <QtQml/qqmlregistration.h>

#include <QObject>
#include <QString>
#include <QColor>
#include <QVariantList>
#include <QtMath>

#include <cmath>

class ChartClass : public QObject {

    Q_OBJECT

    QML_ELEMENT

    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QString parameter READ parameter WRITE setParameter NOTIFY parameterChanged)
    Q_PROPERTY(ChartType chartType READ chartType WRITE setChartType NOTIFY chartTypeChanged)
    Q_PROPERTY(QVariantList x_values READ x_values)
    Q_PROPERTY(QVariantList y_values READ y_values)

public:
    ChartClass(QObject* parent = nullptr) : QObject(parent){
        m_color = QColor("green");
        m_parameter = "Test";
        m_char_type = Sin_chart;
        for (double v = 0.0; v <= 5.0; v+= 0.1){
            m_x_values.append(v);
        }
        m_y_values.clear();
        sin_calc();
    }
    ~ChartClass(){}

    enum ChartType {Sin_chart, Mod_chart, Square_chart, Equel_chart, Log2_chart};
    Q_ENUM(ChartType)

    QColor color() const { return m_color; }
    QString parameter() const { return m_parameter; }
    ChartType chartType() const { return m_char_type; }
    QVariantList x_values() const { return m_x_values; }
    QVariantList y_values() const { return m_y_values; }

    void setColor(QColor color){
        m_color = color;
        emit colorChanged(color);
    }
    void setParameter(QString parameter){
        m_parameter = parameter;
        emit parameterChanged(parameter);
    }
    void setChartType(ChartType type){
        m_char_type = type;
        emit chartTypeChanged(type);
    }

signals:
    void colorChanged(QColor);
    void parameterChanged(QString);
    void chartTypeChanged(ChartType);

public slots:
    void changeType(ChartType type){
        if (type == Sin_chart){
            sin_calc();
            return;
        }
        if (type == Equel_chart){
            linear_calc();
            return;
        }
        if (type == Mod_chart){
            modulo_calc();
            return;
        }
        if (type == Square_chart){
            square_calc();
            return;
        }
        if (type == Log2_chart){
            log2_calc();
            return;
        }
    }

private:
    QColor m_color;
    QString m_parameter;
    ChartType m_char_type;
    QVariantList m_x_values;
    QVariantList m_y_values;

    void sin_calc(){
        m_y_values.clear();
        for (const auto& val : m_x_values){
            m_y_values.append(qSin(val.value<double>()));
        }
    }

    void linear_calc(){
        m_y_values.clear();
        for (const auto& val : m_x_values){
            m_y_values.append(val);
        }
    }

    void modulo_calc(){
        m_y_values.clear();
        for (const auto& val : m_x_values){
            m_y_values.append(qAbs(val.value<double>() - 2.5));
        }
    }

    void square_calc(){
        m_y_values.clear();
        for (const auto& val : m_x_values){
            m_y_values.append(qPow(val.value<double>(), 2));
        }
    }

    void log2_calc(){
        m_y_values.clear();
        for (const auto& val : m_x_values){
//            double tmp = val.value<double>();
            m_y_values.append(std::log2(val.value<double>()));
        }
    }
};
