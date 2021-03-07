#pragma once
#ifndef _MYIMAGE_
#define _MYIMAGE_
//������Ϊ�洢ԭ�ͺͲ�������Ķ���
class MyImage
{
public:
	enum ImageType
	{
		LAST,
		Spot,
	};
	//���麯����Ϊ������д
	virtual MyImage* clone() = 0;

	virtual ImageType getImageType() = 0;

	virtual void Draw() = 0;
	/// <summary>
	/// ����ԭ��
	/// </summary>
	/// <param name="imgType"></param>
	/// <returns></returns>
	static MyImage* FindAndClone(ImageType imgType)
	{
		for (int i = 0; i < _nextSlot; i++)
		{
			if (propertyArray[i]->getImageType() == imgType)
			{
				return propertyArray[i]->clone();
			}

		}
	}

	static void AddProperty(MyImage* img)
	{
		propertyArray[_nextSlot++] = img;
	}

private:
	static MyImage* propertyArray[10];
	static int _nextSlot;
};
MyImage* MyImage::propertyArray[10];
int MyImage::_nextSlot = 1;

class LandStatImage :public MyImage
{
public:
	MyImage* clone()
	{
		return new LandStatImage(1);
	}
	ImageType getImageType()
	{
		return LAST;
	}
	void Draw()
	{
		
	}
private:
	static LandStatImage _landStatImg;
	static int _count;
	LandStatImage()
	{
		AddProperty(this);
		id = 0;
	}
	//ֻ�ǵ���Ϊ�˿����ں��渴��ʱ��������ʹ��
	LandStatImage(int d)
	{
		id = _count++;
	}
	int id;

};
LandStatImage LandStatImage::_landStatImg;
int LandStatImage::_count = 1;

class SpotImage :public MyImage
{
public:
	MyImage* clone()
	{
		return new SpotImage(1);
	}
	ImageType getImageType()
	{
		return Spot;
	}
	void Draw()
	{

	}
private:
	static SpotImage _spotImg;
	static int _count;
	SpotImage()
	{
		AddProperty(this);
		id = 0;
	}
	//ֻ�ǵ���Ϊ�˿����ں��渴��ʱ��������ʹ��
	SpotImage(int d)
	{
		id = _count++;
	}
	int id;

};
SpotImage SpotImage::_spotImg;
int SpotImage::_count = 1;
#endif // !_MYIMAGE_
