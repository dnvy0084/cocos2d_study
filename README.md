# Cocos2D-X

cocos2d-x study 저장소. README를 이용해서 설치 및 프로그래밍에 대한 정리 중. 

### Cocos2D 설치
* [공식 홈페이지](http://www.cocos2d-x.org/) 에서 [Download](http://www.cocos2d-x.org/download)하여 설치
* 한글이 포함되지 않는 경로에 압축 해제하면 설치 완료
* 설치 경로상의 \tools\cocos2d-console\bin 폴더에서 cocos.bat 파일을 이용해서 새 프로젝트를 생성할 수 있음.(환경변수로 등록하면 좋을듯)
* cocos new -p {**PACKAGE_NAME**} -l {**LANGUAGE**( cpp | lua | js )} -d {**DIRECTORY**} {**PROJECT_NAME**(=생성 폴더 이름)} 형식으로 새로운 프로젝트 생성(필요 파일 복사)

### Hello World
* cocos2d는 Director라는 singletone instance가 push, pop, replace된 Scene을 플랫폼에 맞는 native graphic api를 이용해 rendering 해준다. 
* Scene은 화면을 이루는 단위이면 Scene안에서 Layer를 addChild, removeChild하며 세부적인 화면 전환도 만들 수 있다. 
* Scene과 Scene사이의 전환은 Director::getInstace()->replaceScene, Director::push(pop)Scene을 이용하며, Transtion Class를 이용하면 준비된 화면전환 효과를 사용할 수 있다.
* 