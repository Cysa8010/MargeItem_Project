#include "transform.h"
#include "component.h"

Transform::Transform()
{

}

Transform::~Transform()
{
}

void Transform::Update()
{
	this->GetSiblingIndex();
}

void Transform::DetachChildren()
{
	// �͂���
}

Transform * Transform::Find(const char * name)
{
	// �ċA�I�ɂ��̃R���|�[�l���g��
	return nullptr;
}

Transform * Transform::GetChild(int index)
{
	//�C���f�b�N�X����q�� transform ���擾���܂�
	return (Transform*)nullptr;
}

int Transform::GetSiblingIndex()
{
	//���݂� Transform �̃C���f�b�N�X���擾���܂�
	return 0;
}

Vector3 Transform::InverseTransformDirection(Vector3 wdirection)
{
	return Vector3();
}

Vector3 Transform::InverseTransformDirection(float x, float y, float z)
{
	return Vector3();
}

Vector3 Transform::InverseTransformPoint(Vector3 wposition)
{
	return Vector3();
}

Vector3 Transform::InverseTransformPoint(float x, float y, float z)
{
	return Vector3();
}

Vector3 Transform::InverseTransformVector(Vector3 wvector)
{
	return wvector;
}

Vector3 Transform::InverseTransformVector(float x, float y, float z)
{
	return Vector3(x, y, z);
}

bool Transform::IsChildOf(Transform * parent)
{
	//�ċA�t��������
	return false;
}

void Transform::LookAt(Transform * target, Vector3 worldUp)
{
	// ������]?
}

void Transform::Rotate(Vector3 eulers, Space relativeTo)
{
	// ������]
}

void Transform::RotateAround(Vector3 point, Vector3 axis, float angle)
{
	// �����_��]
}

void Transform::SetAsFirstSibling()
{
	// �e�ɃA�N�Z�X���ď��Ԃ�ύX
}

void Transform::SetAsLastSibling()
{
	// �e�ɃA�N�Z�X���ď��Ԃ�ύX
}

void Transform::SetParent(Transform * parent, bool worldPositionStays)
{
	// �e���Z�b�g
}

void Transform::SetSiblingIndex(int index)
{
	//�w��̃C���f�b�N�X�Ɏ��g��index���ړ������܂��B
}

Vector3 Transform::TransformDirection(Vector3 ldirection)
{
	return Vector3();
}

Vector3 Transform::TransformDirection(float x, float y, float z)
{
	return Vector3();
}

Vector3 Transform::TransformPoint(Vector3 lposition)
{
	return Vector3();
}

Vector3 Transform::TransformPoint(float x, float y, float z)
{
	return Vector3();
}

Vector3 Transform::TransformVector(Vector3 lvector)
{
	return Vector3();
}

Vector3 Transform::TransformVector(float x, float y, float z)
{
	return Vector3();
}

void Transform::Translate(Vector3 translation, Space relativeTo)
{
	//translation �̕����Ƌ����Ɉړ����܂�
	position += translation;
}
