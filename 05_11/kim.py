scores = (('박동규', 88, 95, 90), ('강영민', 85, 90, 95), ('박동민', 70, 90, 80), ('홍승주', 90, 90, 95))

def mean_math_score(scores) :
    zipped = zip(scores[0], scores[1], scores[2], scores[3])
    
    name, korean_score, math_score, science_score = zipped
    #print(name, korean_score, math_score, science_score)

    math_sum = 0
    for score in math_score:
        math_sum += score
    
    mean_math = math_sum / 4
    print(f"학생들의 수학 성적의 평균은 {mean_math}입니다.")
    
    return mean_math

def mean_math_sci_score(scores) :
    zipped = zip(scores[0], scores[1], scores[2], scores[3])
    
    name, korean_score, math_score, science_score = zipped
    #print(name, korean_score, math_score, science_score)

    math_sum = 0
    for score in math_score:
        math_sum += score
    
    mean_math = math_sum / 4

    sci_sum = 0
    for score in science_score:
        sci_sum += score
    
    mean_sci = sci_sum / 4

    mean_math_sci = (mean_math + mean_sci) / 2
    print(f"학생들의 수학과 과학 성적의 평균은 {mean_math_sci}입니다.")
    
    return mean_math_sci

def mean_student_score(scores) :
    zipped = zip(scores[0], scores[1], scores[2], scores[3])
    name, korean_score, math_score, science_score = zipped

    student_dic = {}

    for i in range(len(name)) :
        student_avg = (korean_score[i] + math_score[i] + science_score[i]) / 3
        student_dic[name[i]] = student_avg

    print("<이름 평균성적>")
    print("-------------")
    for name in student_dic : 
        print(name, student_dic[name])

    return

mean_math_score(scores)
mean_math_sci_score(scores)
mean_student_score(scores)


