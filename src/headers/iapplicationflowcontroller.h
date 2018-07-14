#ifndef IAPPLICATIONFLOWCONTROLLER_H
#define IAPPLICATIONFLOWCONTROLLER_H

class IApplicationFlowController
{
public:
    virtual ~IApplicationFlowController() {}
    virtual void run() = 0;
};

#endif // IAPPLICATIONFLOWCONTROLLER_H


