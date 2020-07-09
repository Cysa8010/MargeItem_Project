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
	// はがす
}

Transform * Transform::Find(const char * name)
{
	// 再帰的にこのコンポーネントの
	return nullptr;
}

Transform * Transform::GetChild(int index)
{
	//インデックスから子の transform を取得します
	return (Transform*)nullptr;
}

int Transform::GetSiblingIndex()
{
	//現在の Transform のインデックスを取得します
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
	//再帰逆引き検索
	return false;
}

void Transform::LookAt(Transform * target, Vector3 worldUp)
{
	// 多軸回転?
}

void Transform::Rotate(Vector3 eulers, Space relativeTo)
{
	// 自軸回転
}

void Transform::RotateAround(Vector3 point, Vector3 axis, float angle)
{
	// 注視点回転
}

void Transform::SetAsFirstSibling()
{
	// 親にアクセスして順番を変更
}

void Transform::SetAsLastSibling()
{
	// 親にアクセスして順番を変更
}

void Transform::SetParent(Transform * parent, bool worldPositionStays)
{
	// 親をセット
}

void Transform::SetSiblingIndex(int index)
{
	//指定のインデックスに自身のindexを移動させます。
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
	//translation の方向と距離に移動します
	position += translation;
}
