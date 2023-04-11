// 6장-11.NOTE.H
// Note class의 interface로서 
// 구현 class로서 friend class인 NoteImpl를 사용한다.
class Note{
    // NoteImpl * ni; //class keyword가 없어 error 발생
    class NoteImpl* ni;
public:
    Note (int pitch, int duration);
    ~Note ();
    void Sound ();
    void Increase (int delta);
    void Modulate (int cicles);
} ;