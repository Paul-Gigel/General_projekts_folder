#ifndef AUDIOPLAYER_ABTRACT_Audioformat
#define AUDIOPLAYER_ABTRACT_Audioformat
class Audioformat	{
public:
	virtual void abspielen() =0;
	virtual void info() =0;
    virtual void next() final   {

    }
    virtual ~Audioformat()  {
        std::cout<<"Destruktor Audioformat\n";
    }
};
#endif
