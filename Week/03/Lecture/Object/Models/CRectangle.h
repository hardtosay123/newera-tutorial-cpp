class CRectangle
{
    private:
        int width, height;
    public:
        void setValues(int, int);
        int getArea();
};
void CRectangle::setValues(int w, int h)
{
    width = w;
    height = h;
}
int CRectangle::getArea()
{
    return (width*height);
}