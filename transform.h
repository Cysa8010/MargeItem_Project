/**
 * @file xx.h
 * @brief 簡易的説明
 * @author Tsukasa Yamato
 * @date 開発日
 * @note 補足説明
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
/*{// 実装はどっかライブラリを作ってやる
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
	 * @details 引数なしのコンストラクタ。初期化を担う
	*/
	Transform();
	/**
	 * @fn ~Transform()
	 * @brief destructor
	 * @details 解放処理など終了処理を担う
	*/
	~Transform() override;
	/**
	 * @fn void Update(void)
	 * @brief updateFunc
	 * @param void
	 * @return void
	 * @details 更新処理, 兄弟や子がいる場合はまわす
	*/
	void Update()override;
	/**
	 * @fn void DetachChildren();
	 * @brief remove to this children.
	 * @details すべての子オブジェクトを親オブジェクトから切り離します(c++では使い道があまりない)
	 * @note 未実装
	*/
	void DetachChildren();
	/**
	 * @fn Transform* Find(const char* name)
	 * @brief SearchFunc
	 * @param[in] (name) const char* : 検索する文字列
	 * @return True : オブジェクトのTransform / False : null
	 * @details 自分のいる階層の下から再帰的に検索
	*/
	Transform* Find(const char* name);
	/**
	 * @fn Transform* GetChild(int index)
	 * @brief GetChildFunc
	 * @param[in] (index) int : 指定する子の番号
	 * @return True : オブジェクトのTransform / False : null
	 * @details 指定した子の情報を取得する。0スタート。孫は含まない。
	*/
	Transform* GetChild(int index);
	/**
	 * @fn int	GetSiblingIndex()
	 * @brief GetSiblingIndexFunc
	 * @return 自分の番号
	 * @details 特になし
	*/
	int	GetSiblingIndex();
	/**
	 * @fn Vector3	InverseTransformDirection(Vector3 wdirection)
	 * @brief World convert to Local
	 * @param 型 引数型
	 * @return 戻り値の説明
	 * @details 詳細な説明
	 * @note 未実装
	*/
	Vector3	InverseTransformDirection(Vector3 wdirection);//ワールド空間からローカル空間へ direction を変換します。Transform.TransformDirection とは逆の機能になります
	/**
	 * @fn Vector3 InverseTransformDirection(float x, float y, float z)
	 * @brief World convert to Local
	 * @param 型 引数型
	 * @return 戻り値の説明
	 * @details 詳細な説明
	 * @note 未実装
	*/
	Vector3	InverseTransformDirection(float x, float y, float z);//ワールド空間からローカル空間へ direction を変換します。Transform.TransformDirection とは逆の機能になります
	/**
	 * @fn Vector3 InverseTransformPoint(Vector3 wposition)
	 * @brief World convert to Local
	 * @param 型 引数型
	 * @return 戻り値の説明
	 * @details 詳細な説明
	 * @note 未実装
	*/
	Vector3	InverseTransformPoint(Vector3 wposition);//ワールド空間からローカル空間へ position を変換します。
	/**
	 * @fn Vector3 InverseTransformPoint(float x, float y, float z)
	 * @brief World convert to Local
	 * @param 型 引数型
	 * @return 戻り値の説明
	 * @details 詳細な説明
	 * @note 未実装
	*/
	Vector3	InverseTransformPoint(float x, float y, float z);//ワールド空間からローカル空間へ position を変換します。
	/**
	 * @fn Vector3 InverseTransformVector(Vector3 wvector)
	 * @brief World convert to Local
	 * @param 型 引数型
	 * @return 戻り値の説明
	 * @details ワールド空間からローカル空間へ vector を変換します。
	 Transform.TransformVector の逆の機能です。
	 * @note 未実装
	*/
	Vector3	InverseTransformVector(Vector3 wvector);
	/**
	 * @fn Vector3 InverseTransformVector(float x, float y, float z)
	 * @brief World convert to Local
	 * @param 型 引数型
	 * @return 戻り値の説明
	 * @details 詳ワールド空間からローカル空間へ vector を変換します。
	 Transform.TransformVector の逆の機能です。これはスケールの影響を受けます。
	 * @note 未実装
	*/
	Vector3 InverseTransformVector(float x, float y, float z);
	/**
	 * @fn bool IsChildOf(Transform* parent)
	 * @brief Find out if this is a child.
	 * @param[in] (parent) Transform* : 親
	 * @return 親かどうか
	 * @details 自身が指定したオブジェクトの子に含まれるかどうかを返します。親を調べたい時に使用します。
	 * @note 未実装
	*/
	bool IsChildOf(Transform* parent);
	/**
	 * @fn void LookAt(Transform* target, Vector3 worldUp = Vector3::Up())
	 * @brief ???
	 * @param[in] (target) Transform* : 向かせたい先の対象
	 * @param[in] (worldUp) Vector3 : 上方向
	 * @details 対象のTransformを設定しその方向へと向かせます
	 * @note 未実装
	*/
	void LookAt(Transform* target, Vector3 worldUp = Vector3::Up());
	/**
	 * @fn void Rotate(Vector3 eulers, Space relativeTo = Space::Self)
	 * @brief RotateFunc
	 * @param[in] (eulers) Vector3 : オイラー角
	 * @param[in] (relativeTo) Space : 座標空間
	 * @details このオブジェクトを指定したオイラー角で回転させます。デフォルトでローカル基準で回転させます。
	 * @note 未実装
	*/
	void Rotate(Vector3 eulers, Space relativeTo = Space::Self);
	/**
	 * @fn void RotateAround(Vector3 point, Vector3 axis, float angle)
	 * @brief AroundRotateFunc
	 * @param[in] (point) Vector3 : 中心点
	 * @param[in] (axis) Vector3 : 回転軸
	 * @param[in] (angle) float : 回転角
	 * @details ワールド座標の point を中心とした軸( axis )で angle 度回転させます。これは Transform の位置と回転が同時に変更されます。
	 * @note 未実装
	*/
	void RotateAround(Vector3 point, Vector3 axis, float angle);
	/**
	 * @fn void SetAsFirstSibling()
	 * @brief FirstSibling move func
	 * @details ローカルの Transform リストで、一番最初の順番になるよう移動します。
	 * @note 未実装
	*/
	void SetAsFirstSibling();
	/**
	 * @fn void SetAsLastSibling()
	 * @brief LastSibling move func
	 * @details ローカルの Transform リストで、一番最後の順番になるよう移動します。
	 * @note 未実装
	*/
	void SetAsLastSibling();
	/**
	 * @fn void SetParent(Transform parent, bool worldPositionStays = true)
	 * @brief parent set func
	 * @param[in] (parent) Transform* : 親
	 * @param[in] (worldPositionStays) bool : world値の維持 / 非維持
	 * @details trueの場合、LocalのPosition, Rotation, Scaleは以前のWorldでの値を維持したまま、Localの値を変更
	*/
	void SetParent(Transform* parent, bool worldPositionStays = true);
	/**
	 * @fn void SetPositionAndRotation (Vector3 position, Quaternion rotation)
	 * @brief position and rotation set func
	 * @param[in] (position) Vector3 : 座標
	 * @param[in] (rotation) Quaternion : 姿勢
	 * @details Sets the world space position and rotation of the Transform component.
	 * @note 非実装
	*/
	//void SetPositionAndRotation(Vector3 position, Quaternion rotation) {}
	/**
	 * @fn void SetSiblingIndex(int index)
	 * @brief SetSiblingIndexFunc
	 * @param[in] (index) int : インデックス
	 * @details 指定のインデックスに自身のindexを移動させます。
	*/
	void SetSiblingIndex(int index);
	/**
	 * @fn Vector3	TransformDirection(Vector3 ldirection)
	 * @brief Local to world convert
	 * @param 型 引数型
	 * @details ローカル空間からワールド空間へ direction を変換します
	*/
	Vector3	TransformDirection(Vector3 ldirection);//
	/**
	 * @fn Vector3 TransformDirection(float x, float y, float z);
	 * @brief Local to world convert
	 * @param 型 引数型
	 * @details ローカル空間からワールド空間へ direction を変換します
	*/
	Vector3 TransformDirection(float x, float y, float z);
	/**
	 * @fn Vector3 TransformPoint(Vector3 lposition)
	 * @brief Local to world convert
	 * @param 型 引数型
	 * @details ローカル空間からワールド空間へ position を変換します。
	*/
	Vector3	TransformPoint(Vector3 lposition);//
	/**
	 * @fn Vector3 TransformPoint(float x, float y, float z)
	 * @brief Local to world convert
	 * @param 型 引数型
	 * @details ローカル空間からワールド空間へ position を変換します。
	*/
	Vector3 TransformPoint(float x, float y, float z);
	/**
	 * @fn Vector3	TransformVector(Vector3 lvector)
	 * @brief Local to world convert
	 * @param 型 引数型
	 * @details ローカル空間からワールド空間へ vector を変換します。
	*/
	Vector3	TransformVector(Vector3 lvector);//
	/**
	 * @fn Vector3 TransformVector(float x, float y, float z)
	 * @brief Local to world convert
	 * @param 型 引数型
	 * @details ローカル空間からワールド空間へ vector を変換します。
	*/
	Vector3 TransformVector(float x, float y, float z);
	/**
	 * @fn void Translate(Vector3 translation, Space relativeTo = Space::Self)
	 * @brief Coord move func
	 * @param[in] (translation) Vector3 : 長さあり方向ベクトル
	 * @param[in] (relativeTo) Space : 座標空間
	 * @details translation の方向と距離に移動します
	*/
	void Translate(Vector3 translation, Space relativeTo = Space::Self);
	

private:
Transform root;			    // 階層の一番上の Transform
Transform parent;			    // Transform の親
int childCount;         // このゲームオブジェクトについている子の数
bool hasChanged;		    // フラグが最後に 'false' に設定されたときから Transform になんらかの変更があったかどうか
//int hierarchyCapacity;  // transform のヒエラルキーデータ構造の transform 容量
//int hierarchyCount;	    // transform のヒエラルキーデータ構造の transform の数
Vector3 localPosition;	    // 親の Transform オブジェクトから見た相対的な位置
Quaternion localRotation;	    // The rotation of the transform relative to the transform rotation of the parent.
Vector3 localEulerAngles;   // 親の Transform オブジェクトから見た相対的なオイラー角としての回転値
Vector3 localScale;		    // The scale of the transform relative to the GameObjects parent.
Vector3 position;		    // The world space position of the Transform.
Quaternion rotation;		    // A Quaternion that stores the rotation of the Transform in world space.
Vector3 eulerAngles;	    // オイラー角としての角度
Vector3 lossyScale;		    // オブジェクトのグローバルスケール（読み取り専用）
Vector3 forward;		    // Returns a normalized vector representing the blue axis of the transform in world space.
Vector3 right;			    // ワールド空間の Transform の赤軸
Vector3 up;				    // ワールド空間の Transform の緑軸
Matrix4x4 localToWorldMatrix; // ローカル座標からワールド座標へ変換した行列（読み取り専用）
Matrix4x4 worldToLocalMatrix; // ワールド座標からローカル座標へ変換した行列（読み取り専用）

};

#endif // !TRANSFORM_H_
