#include "log4qt/varia/binaryeventfilter.h"

#include "log4qt/binaryloggingevent.h"

namespace Log4Qt
{

BinaryEventFilter::BinaryEventFilter(QObject *parent)
    : Filter(parent)
    , mAcceptBinaryEvents{true}
{
}

Filter::Decision BinaryEventFilter::decide(const LoggingEvent &rEvent) const
{
    bool isBinaryEvent = dynamic_cast<const BinaryLoggingEvent *>(&rEvent) != nullptr;

    if (!isBinaryEvent)
        return Filter::NEUTRAL;

    if (mAcceptBinaryEvents)
        return Filter::ACCEPT;
    else
        return Filter::DENY;
}


} // namespace Log4Qt

#include "moc_binaryeventfilter.cpp"
