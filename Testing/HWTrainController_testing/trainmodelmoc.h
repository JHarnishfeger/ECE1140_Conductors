#ifndef TRAINMODELMOC_H
#define TRAINMODELMOC_H



class trainModelMoc
{
public:
    trainModelMoc();

    //boolean operation values
    bool brakes,eBrakes;
    bool interiorLights,exteriorLights;
    bool leftDoor,rightDoor;

    double power;
    double actualSpeed;



    //lights
    void setInteriorLights(bool interiorLights);
    void setExteriorLights(bool exteriorLights);
    bool getInteriorLights();
    bool getExteriorLights();

    //doors
    void setLeftDoor(bool leftdoor);
    void setRightDoor(bool rightdoor);
    bool getLeftDoor();
    bool getRightDoor();

    //brakes
    void setBrakes(bool b);
    bool getBrakes();
    void setEbrakes(bool Eb);
    bool getEbrakes();

    void setPower(double pow);
    double getPower();

    double getSpeed();
    void setSpeed(double speed);
};

#endif // TRAINMODELMOC_H
