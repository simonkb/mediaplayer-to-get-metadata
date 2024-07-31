// metadataimageprovider.h
#ifndef METADATAIMAGEPROVIDER_H
#define METADATAIMAGEPROVIDER_H

#include <QQuickImageProvider>
#include <QImage>
#include <QObject>
class MetadataImageProvider : public QQuickImageProvider
{
    Q_OBJECT
public:
    MetadataImageProvider();
    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize) override;

public slots:
    Q_INVOKABLE void updateImage(const QVariant &imageVariant);

private:
    QImage m_image;
};

#endif // METADATAIMAGEPROVIDER_H

