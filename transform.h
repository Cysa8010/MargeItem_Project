/**
 * @file xx.h
 * @brief �ȈՓI����
 * @author Tsukasa Yamato
 * @date �J����
 * @note �⑫����
 */
#ifndef TRANSFORM_H_
#define TRANSFORM_H_

//class IObject;
class IComponent;
struct Vector3
{
	float x, y, z;
	Vector3() :x(0.f), y(0.f), z(0.f) {}
	Vector3(float x, float y, float z) :x(x), y(y), z(z) {}
	static Vector3 Up()
	{
		return Vector3(0.f, 1.0f, 0.f);
	}
};
struct Quaternion
/*{// �����͂ǂ������C�u����������Ă��
	const float kEpsilon = 1E-06F;
	float x, y, z, w;

	Quaternion(float x, float y, float z, float w);
}*/;
struct Matrix4x4
/*{
	float m[4][4];
}*/;
enum Space
{
	World = 0,
	Self
};

class Transform :public Component
{
public:
	/**
	 * @fn Transform()
	 * @brief DefaultConstructor
	 * @details �����Ȃ��̃R���X�g���N�^�B��������S��
	*/
	Transform();
	/**
	 * @fn ~Transform()
	 * @brief destructor
	 * @details ��������ȂǏI��������S��
	*/
	~Transform() override;
	/**
	 * @fn void Update(void)
	 * @brief updateFunc
	 * @param void
	 * @return void
	 * @details �X�V����, �Z���q������ꍇ�͂܂킷
	*/
	void Update()override;
	/**
	 * @fn void DetachChildren();
	 * @brief remove to this children.
	 * @details ���ׂĂ̎q�I�u�W�F�N�g��e�I�u�W�F�N�g����؂藣���܂�(c++�ł͎g���������܂�Ȃ�)
	 * @note ������
	*/
	void DetachChildren();
	/**
	 * @fn Transform* Find(const char* name)
	 * @brief SearchFunc
	 * @param[in] (name) const char* : �������镶����
	 * @return True : �I�u�W�F�N�g��Transform / False : null
	 * @details �����̂���K�w�̉�����ċA�I�Ɍ���
	*/
	Transform* Find(const char* name);
	/**
	 * @fn Transform* GetChild(int index)
	 * @brief GetChildFunc
	 * @param[in] (index) int : �w�肷��q�̔ԍ�
	 * @return True : �I�u�W�F�N�g��Transform / False : null
	 * @details �w�肵���q�̏����擾����B0�X�^�[�g�B���͊܂܂Ȃ��B
	*/
	Transform* GetChild(int index);
	/**
	 * @fn int	GetSiblingIndex()
	 * @brief GetSiblingIndexFunc
	 * @return �����̔ԍ�
	 * @details ���ɂȂ�
	*/
	int	GetSiblingIndex();
	/**
	 * @fn Vector3	InverseTransformDirection(Vector3 wdirection)
	 * @brief World convert to Local
	 * @param �^ �����^
	 * @return �߂�l�̐���
	 * @details �ڍׂȐ���
	 * @note ������
	*/
	Vector3	InverseTransformDirection(Vector3 wdirection);//���[���h��Ԃ��烍�[�J����Ԃ� direction ��ϊ����܂��BTransform.TransformDirection �Ƃ͋t�̋@�\�ɂȂ�܂�
	/**
	 * @fn Vector3 InverseTransformDirection(float x, float y, float z)
	 * @brief World convert to Local
	 * @param �^ �����^
	 * @return �߂�l�̐���
	 * @details �ڍׂȐ���
	 * @note ������
	*/
	Vector3	InverseTransformDirection(float x, float y, float z);//���[���h��Ԃ��烍�[�J����Ԃ� direction ��ϊ����܂��BTransform.TransformDirection �Ƃ͋t�̋@�\�ɂȂ�܂�
	/**
	 * @fn Vector3 InverseTransformPoint(Vector3 wposition)
	 * @brief World convert to Local
	 * @param �^ �����^
	 * @return �߂�l�̐���
	 * @details �ڍׂȐ���
	 * @note ������
	*/
	Vector3	InverseTransformPoint(Vector3 wposition);//���[���h��Ԃ��烍�[�J����Ԃ� position ��ϊ����܂��B
	/**
	 * @fn Vector3 InverseTransformPoint(float x, float y, float z)
	 * @brief World convert to Local
	 * @param �^ �����^
	 * @return �߂�l�̐���
	 * @details �ڍׂȐ���
	 * @note ������
	*/
	Vector3	InverseTransformPoint(float x, float y, float z);//���[���h��Ԃ��烍�[�J����Ԃ� position ��ϊ����܂��B
	/**
	 * @fn Vector3 InverseTransformVector(Vector3 wvector)
	 * @brief World convert to Local
	 * @param �^ �����^
	 * @return �߂�l�̐���
	 * @details ���[���h��Ԃ��烍�[�J����Ԃ� vector ��ϊ����܂��B
	 Transform.TransformVector �̋t�̋@�\�ł��B
	 * @note ������
	*/
	Vector3	InverseTransformVector(Vector3 wvector);
	/**
	 * @fn Vector3 InverseTransformVector(float x, float y, float z)
	 * @brief World convert to Local
	 * @param �^ �����^
	 * @return �߂�l�̐���
	 * @details �ڃ��[���h��Ԃ��烍�[�J����Ԃ� vector ��ϊ����܂��B
	 Transform.TransformVector �̋t�̋@�\�ł��B����̓X�P�[���̉e�����󂯂܂��B
	 * @note ������
	*/
	Vector3 InverseTransformVector(float x, float y, float z);
	/**
	 * @fn bool IsChildOf(Transform* parent)
	 * @brief Find out if this is a child.
	 * @param[in] (parent) Transform* : �e
	 * @return �e���ǂ���
	 * @details ���g���w�肵���I�u�W�F�N�g�̎q�Ɋ܂܂�邩�ǂ�����Ԃ��܂��B�e�𒲂ׂ������Ɏg�p���܂��B
	 * @note ������
	*/
	bool IsChildOf(Transform* parent);
	/**
	 * @fn void LookAt(Transform* target, Vector3 worldUp = Vector3::Up())
	 * @brief ???
	 * @param[in] (target) Transform* : ������������̑Ώ�
	 * @param[in] (worldUp) Vector3 : �����
	 * @details �Ώۂ�Transform��ݒ肵���̕����ւƌ������܂�
	 * @note ������
	*/
	void LookAt(Transform* target, Vector3 worldUp = Vector3::Up());
	/**
	 * @fn void Rotate(Vector3 eulers, Space relativeTo = Space::Self)
	 * @brief RotateFunc
	 * @param[in] (eulers) Vector3 : �I�C���[�p
	 * @param[in] (relativeTo) Space : ���W���
	 * @details ���̃I�u�W�F�N�g���w�肵���I�C���[�p�ŉ�]�����܂��B�f�t�H���g�Ń��[�J����ŉ�]�����܂��B
	 * @note ������
	*/
	void Rotate(Vector3 eulers, Space relativeTo = Space::Self);
	/**
	 * @fn void RotateAround(Vector3 point, Vector3 axis, float angle)
	 * @brief AroundRotateFunc
	 * @param[in] (point) Vector3 : ���S�_
	 * @param[in] (axis) Vector3 : ��]��
	 * @param[in] (angle) float : ��]�p
	 * @details ���[���h���W�� point �𒆐S�Ƃ�����( axis )�� angle �x��]�����܂��B����� Transform �̈ʒu�Ɖ�]�������ɕύX����܂��B
	 * @note ������
	*/
	void RotateAround(Vector3 point, Vector3 axis, float angle);
	/**
	 * @fn void SetAsFirstSibling()
	 * @brief FirstSibling move func
	 * @details ���[�J���� Transform ���X�g�ŁA��ԍŏ��̏��ԂɂȂ�悤�ړ����܂��B
	 * @note ������
	*/
	void SetAsFirstSibling();
	/**
	 * @fn void SetAsLastSibling()
	 * @brief LastSibling move func
	 * @details ���[�J���� Transform ���X�g�ŁA��ԍŌ�̏��ԂɂȂ�悤�ړ����܂��B
	 * @note ������
	*/
	void SetAsLastSibling();
	/**
	 * @fn void SetParent(Transform parent, bool worldPositionStays = true)
	 * @brief parent set func
	 * @param[in] (parent) Transform* : �e
	 * @param[in] (worldPositionStays) bool : world�l�̈ێ� / ��ێ�
	 * @details true�̏ꍇ�ALocal��Position, Rotation, Scale�͈ȑO��World�ł̒l���ێ������܂܁ALocal�̒l��ύX
	*/
	void SetParent(Transform* parent, bool worldPositionStays = true);
	/**
	 * @fn void SetPositionAndRotation (Vector3 position, Quaternion rotation)
	 * @brief position and rotation set func
	 * @param[in] (position) Vector3 : ���W
	 * @param[in] (rotation) Quaternion : �p��
	 * @details Sets the world space position and rotation of the Transform component.
	 * @note �����
	*/
	//void SetPositionAndRotation(Vector3 position, Quaternion rotation) {}
	/**
	 * @fn void SetSiblingIndex(int index)
	 * @brief SetSiblingIndexFunc
	 * @param[in] (index) int : �C���f�b�N�X
	 * @details �w��̃C���f�b�N�X�Ɏ��g��index���ړ������܂��B
	*/
	void SetSiblingIndex(int index);
	/**
	 * @fn Vector3	TransformDirection(Vector3 ldirection)
	 * @brief Local to world convert
	 * @param �^ �����^
	 * @details ���[�J����Ԃ��烏�[���h��Ԃ� direction ��ϊ����܂�
	*/
	Vector3	TransformDirection(Vector3 ldirection);//
	/**
	 * @fn Vector3 TransformDirection(float x, float y, float z);
	 * @brief Local to world convert
	 * @param �^ �����^
	 * @details ���[�J����Ԃ��烏�[���h��Ԃ� direction ��ϊ����܂�
	*/
	Vector3 TransformDirection(float x, float y, float z);
	/**
	 * @fn Vector3 TransformPoint(Vector3 lposition)
	 * @brief Local to world convert
	 * @param �^ �����^
	 * @details ���[�J����Ԃ��烏�[���h��Ԃ� position ��ϊ����܂��B
	*/
	Vector3	TransformPoint(Vector3 lposition);//
	/**
	 * @fn Vector3 TransformPoint(float x, float y, float z)
	 * @brief Local to world convert
	 * @param �^ �����^
	 * @details ���[�J����Ԃ��烏�[���h��Ԃ� position ��ϊ����܂��B
	*/
	Vector3 TransformPoint(float x, float y, float z);
	/**
	 * @fn Vector3	TransformVector(Vector3 lvector)
	 * @brief Local to world convert
	 * @param �^ �����^
	 * @details ���[�J����Ԃ��烏�[���h��Ԃ� vector ��ϊ����܂��B
	*/
	Vector3	TransformVector(Vector3 lvector);//
	/**
	 * @fn Vector3 TransformVector(float x, float y, float z)
	 * @brief Local to world convert
	 * @param �^ �����^
	 * @details ���[�J����Ԃ��烏�[���h��Ԃ� vector ��ϊ����܂��B
	*/
	Vector3 TransformVector(float x, float y, float z);
	/**
	 * @fn void Translate(Vector3 translation, Space relativeTo = Space::Self)
	 * @brief Coord move func
	 * @param[in] (translation) Vector3 : ������������x�N�g��
	 * @param[in] (relativeTo) Space : ���W���
	 * @details translation �̕����Ƌ����Ɉړ����܂�
	*/
	void Translate(Vector3 translation, Space relativeTo = Space::Self);
	

private:
Transform root;			    // �K�w�̈�ԏ�� Transform
Transform parent;			    // Transform �̐e
int childCount;         // ���̃Q�[���I�u�W�F�N�g�ɂ��Ă���q�̐�
bool hasChanged;		    // �t���O���Ō�� 'false' �ɐݒ肳�ꂽ�Ƃ����� Transform �ɂȂ�炩�̕ύX�����������ǂ���
//int hierarchyCapacity;  // transform �̃q�G�����L�[�f�[�^�\���� transform �e��
//int hierarchyCount;	    // transform �̃q�G�����L�[�f�[�^�\���� transform �̐�
Vector3 localPosition;	    // �e�� Transform �I�u�W�F�N�g���猩�����ΓI�Ȉʒu
Quaternion localRotation;	    // The rotation of the transform relative to the transform rotation of the parent.
Vector3 localEulerAngles;   // �e�� Transform �I�u�W�F�N�g���猩�����ΓI�ȃI�C���[�p�Ƃ��Ẳ�]�l
Vector3 localScale;		    // The scale of the transform relative to the GameObjects parent.
Vector3 position;		    // The world space position of the Transform.
Quaternion rotation;		    // A Quaternion that stores the rotation of the Transform in world space.
Vector3 eulerAngles;	    // �I�C���[�p�Ƃ��Ă̊p�x
Vector3 lossyScale;		    // �I�u�W�F�N�g�̃O���[�o���X�P�[���i�ǂݎ���p�j
Vector3 forward;		    // Returns a normalized vector representing the blue axis of the transform in world space.
Vector3 right;			    // ���[���h��Ԃ� Transform �̐Ԏ�
Vector3 up;				    // ���[���h��Ԃ� Transform �̗Ύ�
Matrix4x4 localToWorldMatrix; // ���[�J�����W���烏�[���h���W�֕ϊ������s��i�ǂݎ���p�j
Matrix4x4 worldToLocalMatrix; // ���[���h���W���烍�[�J�����W�֕ϊ������s��i�ǂݎ���p�j

};

#endif // !TRANSFORM_H_
