using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerC : MonoBehaviour
{
    Rigidbody rigid;
    float jumpForce = 120.0f;
    float walkForce = 30.0f;
    float maxWalkSpeed = 2.0f;

    // Start is called before the first frame update
    void Start()
    {
        Application.targetFrameRate = 60;
        this.rigid = GetComponent<Rigidbody>();
    }

    // Update is called once per frame
    void Update()
    {
        //ジャンプする
        if (Input.GetKeyDown(KeyCode.Space)) 
        {
            Debug.Log("押されたよ！");
            this.rigid.AddForce(transform.up * this.jumpForce);
        }

        int keyx = 0;
        int keyz = 0;

        //前後左右移動
        if (Input.GetKey(KeyCode.D))
        {
            keyx = 1;
        }
        if (Input.GetKey(KeyCode.A)) keyx = -1;

        if (Input.GetKey(KeyCode.W)) keyz = 1;
        if (Input.GetKey(KeyCode.S)) keyz = -1;

        //プレイヤーの速度
        float speedx = Mathf.Abs(this.rigid.velocity.x);
        float speedz = Mathf.Abs(this.rigid.velocity.z);

        //スピード制限
        if (speedx < this.maxWalkSpeed)
        {
            this.rigid.AddForce(transform.right * keyx * this.walkForce);
        }

        if (speedz < this.maxWalkSpeed)
        {
            this.rigid.AddForce(transform.forward * keyz * this.walkForce);
        }

        
    }
}
