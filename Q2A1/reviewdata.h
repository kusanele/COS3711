#ifndef REVIEWDATA_H
#define REVIEWDATA_H
#include <QString>
#include <QDateTime>
class ReviewData:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(QDateTime date READ getDate WRITE setDate)
    Q_PROPERTY(bool recommended READ isRecommended WRITE setRecommended)
public:
    ReviewData(const QString &name, const QDateTime &date, bool recommended, QObject *parent =
                                                                             nullptr);
    QString toString() const;
    QString getName() const;
    void setName(const QString &name);
    QDateTime getDate() const;
    void setDate(const QDateTime &date);
    bool isRecommended() const;
    void setRecommended(bool recommended);

private:
    QString name;
    QDateTime date;
    bool recommended;
};
#endif // REVIEWDATA_H
