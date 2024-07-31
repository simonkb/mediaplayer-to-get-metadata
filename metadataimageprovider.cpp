// metadataimageprovider.cpp
#include "metadataimageprovider.h"

MetadataImageProvider::MetadataImageProvider()
    : QQuickImageProvider(QQuickImageProvider::Image)
{
}

QImage MetadataImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    Q_UNUSED(id);

    if (size)
        *size = m_image.size();

    if (requestedSize.width() > 0 && requestedSize.height() > 0)
        return m_image.scaled(requestedSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    return m_image;
}

void MetadataImageProvider::updateImage(const QVariant &imageVariant)
{
    m_image = imageVariant.value<QImage>();
}
