using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraC : MonoBehaviour
{
    public Transform player;  // プレイヤーのTransform
    public Vector3 offset;  // プレイヤーとカメラの相対位置
    public float smoothTime = 0.3f;  // カメラがプレイヤーを追跡する際のスムーズさの調整用パラメータ

    private Vector3 velocity = Vector3.zero;  // カメラ移動時の速度ベクトル
    void LateUpdate()
    {
        // プレイヤーの位置にカメラを追従させる
        Vector3 targetPosition = player.position + offset;
        
        transform.position = Vector3.SmoothDamp(transform.position, targetPosition, ref velocity, smoothTime);
    }
    // Start is called before the first frame update
    void Start()
    {
       
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
