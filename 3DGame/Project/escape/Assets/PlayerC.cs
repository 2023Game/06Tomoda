using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerC : MonoBehaviour
{
    Rigidbody rigid;
    float jumpForce = 120.0f;
    float walkForce = 40.0f;
    float maxWalkSpeed = 2.0f;
    int i = 0;

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
        if (Input.GetKey(KeyCode.D)) keyx = 1;
        if (Input.GetKey(KeyCode.A)) keyx = -1;

        if (Input.GetKey(KeyCode.W)) keyz = 1;
        if (Input.GetKey(KeyCode.S)) keyz = -1;


        float speed = this.rigid.velocity.magnitude;

        if (speed < this.maxWalkSpeed)
        {
            this.rigid.AddForce(transform.right * keyx * this.walkForce);
            this.rigid.AddForce(transform.forward * keyz * this.walkForce);
        }

        

        //回転
        if (Input.GetKeyDown(KeyCode.D))
        {
            transform.Rotate(new Vector3(0, 90, 0));
        }
        if (Input.GetKeyDown(KeyCode.A)) 
        {
            transform.Rotate(new Vector3(0, -90, 0));
        }
        
    }
}
