// 6장-12.NOTE.CPP file
#include <iostream>
#include "6장-11.NOTE.h"
using namespace std;

class NoteImpl {
	friend Note;
private:
	int pitch;// 음의 높낮이
	int duration;
	NoteImpl(int p, int d) :
		pitch(p), duration(d)
	{ }
	// note의 사운드
	void Sound() {
		// 함수 body를 고쳐도 Note::Sound()는 수정하지 않아도 된다
		cout << "Sound(): pitch = " << pitch << ", duration = " << duration << endl;
	}
	void Modulate(int cycles);
};
// Note class의 member 함수들:
 // 변환 생성자
Note::Note(int pitch, int duration) {
	ni = new NoteImpl(pitch, duration);
}
Note :: ~Note() {
	delete ni;
}
void Note::Sound() {//NoteImpl:: Sound()를 사용하여 재작성한 code
	ni->Sound();
}
void Note::Increase(int delta) {
	// 다른 class의 private 데이터에 대한 직접 접근
	ni->pitch += delta;
}
void NoteImpl::Modulate(int cycles) {
	for (int i = 1; i <= cycles; i++) {
		pitch++;
		duration = 1 + i % 2;
		Sound();
	}
}
//*
// Modulate member 함수를 NoteImpl class에 추가함으로써 재작성할 수 있다.
void Note::Modulate(int cycles) {
	cout << "Modulate():: started" << endl;
	for (int i = 1; i <= cycles; i++) {
		ni->pitch++;
		ni->duration = 1 + i % 2;
		cout << "ni->pitch = " << ni->pitch << ", ni->duration = " << ni->duration << endl;
	}
}
//*/