# Cocos2D-X

multi platform graphics library

## 설치
* [공식 홈페이지](http://www.cocos2d-x.org/) 에서 [Download](http://www.cocos2d-x.org/download)하여 설치
* 한글이 포함되지 않는 경로에 압축 해제하면 설치 완료
* 설치 경로상의 \tools\cocos2d-console\bin 폴더에서 cocos.bat 파일을 이용해서 새 프로젝트를 생성할 수 있음.(환경변수로 등록하면 좋을듯)
* cocos new -p {**PACKAGE_NAME**} -l {**LANGUAGE**( cpp | lua | js )} -d {**DIRECTORY**} {**PROJECT_NAME**(=생성 폴더 이름)} 형식으로 새로운 프로젝트 생성(필요 파일 복사)

## Snippets

#### 객체 생성
* cocos2d의 모든 객체는 new대신  Class::create 의 static 멤버함수를 이용해 생성한다. 
* create함수는 해당 클래스를 생성하여 reference count 형식으로 auto release 할 수 있도록 만든 후 포인터를 return 해준다.

#### [**Director**](http://www.cocos2d-x.org/reference/native-cpp/V3.4/d7/df3/classcocos2d_1_1_director.html)
* Scene 관리 및 설정, *Director director = Director::getInstance();* SingleTone 객체로 사용한다. 
* cocos2d는 Director라는 Singletone instance가 push, pop, replace된 Scene을 플랫폼에 맞는 native graphics api를 이용해 rendering 해준다. 

#### [**Scene**](http://www.cocos2d-x.org/reference/native-cpp/V3.4/d4/d5f/classcocos2d_1_1_scene.html)
* Scene은 화면을 이루는 단위이면 Scene안에서 Layer를 addChild, removeChild하며 세부적인 화면 전환도 만들 수 있다. 

#### 화면전환
* Scene과 Scene사이의 전환은 [Director::getInstace()->replaceScene](http://www.cocos2d-x.org/reference/native-cpp/V3.4/d7/df3/classcocos2d_1_1_director.html#ae693d54396ac5f630814cf1f961de830), Director::push(pop)Scene을 이용하며, [Transtion](http://www.cocos2d-x.org/reference/native-cpp/V3.4/da/d00/group__transition.html) 을 이용하면 준비된 화면전환 효과를 사용할 수 있다.

#### 좌표 체계
* cocos2d는 좌하단이 (0, 0), 우상단이(1, 1)의 좌표체계를 가진다. 
* Director::getInstace()->getVisibleSize()로 Size 객체를 가지고 오면 stageSize를 알 수 있다.
* 객체->get(set)AchorPoint(Point(0.5,0.5))로 객체 중점을 중심으로 옮길 수 있다. 기본값은 anchorpoint 는 0.5, 0.5 position은 0, 0