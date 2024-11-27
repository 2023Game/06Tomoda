using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class PlayerC : MonoBehaviour
{
    [SerializeField] GameObject target;

    Rigidbody rigid;
    float jumpForce = 120.0f;
    

    // Start is called before the first frame update
    void Start()
    {
        target = GameObject.Find("Main Camera");
        Application.targetFrameRate = 60;
        this.rigid = GetComponent<Rigidbody>();
    }

    // Update is called once per frame
    void Update()
    {
    
        Transform myTransform = this.transform;

        //ジャンプする
        if (Input.GetKeyDown(KeyCode.Space)) 
        {
            Debug.Log("押されたよ！");
            this.rigid.AddForce(transform.up * this.jumpForce);
        }

        //前後左右移動
        //カメラの位置が（9,6,-10）の時
        if (target.transform.position.z == -10)
        {
            if (target.transform.position.x == 9)
            {
                if (Input.GetKey(KeyCode.D))
                {
                    transform.position -= transform.TransformDirection(Vector3.back) * 3f * Time.deltaTime;
                }
                if (Input.GetKeyDown(KeyCode.D))
                {
                    Vector3 localAngle = myTransform.localEulerAngles;
                    localAngle.y = 90;

                    myTransform.localEulerAngles = localAngle;
                }

                if (Input.GetKey(KeyCode.A))
                {
                    transform.position -= transform.TransformDirection(Vector3.back) * 3f * Time.deltaTime;
                }
                if (Input.GetKeyDown(KeyCode.A))
                {
                    Vector3 localAngle = myTransform.localEulerAngles;
                    localAngle.y = -90;

                    myTransform.localEulerAngles = localAngle;
                }

                if (Input.GetKey(KeyCode.W))
                {
                    transform.position -= transform.TransformDirection(Vector3.back) * 3f * Time.deltaTime;
                }
                if (Input.GetKeyDown(KeyCode.W))
                {
                    Vector3 localAngle = myTransform.localEulerAngles;
                    localAngle.y = 0;

                    myTransform.localEulerAngles = localAngle;
                }

                if (Input.GetKey(KeyCode.S))
                {
                    transform.position -= transform.TransformDirection(Vector3.back) * 3f * Time.deltaTime;
                }
                if (Input.GetKeyDown(KeyCode.S))
                {
                    Vector3 localAngle = myTransform.localEulerAngles;
                    localAngle.y = 180;

                    myTransform.localEulerAngles = localAngle;
                }
            }
        }


        //カメラの座標が（0,6,0）の時
        if (target.transform.position.z == 0)
        {
            if (target.transform.position.x == 0)
            {
                if (Input.GetKey(KeyCode.D))
                {
                    transform.position -= transform.TransformDirection(Vector3.back) * 3f * Time.deltaTime;
                }
                if (Input.GetKeyDown(KeyCode.D))
                {
                    Vector3 localAngle = myTransform.localEulerAngles;
                    localAngle.y = 180;

                    myTransform.localEulerAngles = localAngle;
                }

                if (Input.GetKey(KeyCode.A))
                {
                    transform.position -= transform.TransformDirection(Vector3.back) * 3f * Time.deltaTime;
                }
                if (Input.GetKeyDown(KeyCode.A))
                {
                    Vector3 localAngle = myTransform.localEulerAngles;
                    localAngle.y = 0;

                    myTransform.localEulerAngles = localAngle;
                }

                if (Input.GetKey(KeyCode.W))
                {
                    transform.position -= transform.TransformDirection(Vector3.back) * 3f * Time.deltaTime;
                }
                if (Input.GetKeyDown(KeyCode.W))
                {
                    Vector3 localAngle = myTransform.localEulerAngles;
                    localAngle.y = 90;

                    myTransform.localEulerAngles = localAngle;
                }

                if (Input.GetKey(KeyCode.S))
                {
                    transform.position -= transform.TransformDirection(Vector3.back) * 3f * Time.deltaTime;
                }
                if (Input.GetKeyDown(KeyCode.S))
                {
                    Vector3 localAngle = myTransform.localEulerAngles;
                    localAngle.y = -90;

                    myTransform.localEulerAngles = localAngle;
                }
            }
        }


        //カメラの座標が（9,6,9）の時
        if (target.transform.position.z == 9)
        {
            if (target.transform.position.x == 9)
                if (Input.GetKey(KeyCode.D))
            {
                transform.position -= transform.TransformDirection(Vector3.back) * 3f * Time.deltaTime;
            }
            if (Input.GetKeyDown(KeyCode.D))
            {
                Vector3 localAngle = myTransform.localEulerAngles;
                localAngle.y = -90;

                myTransform.localEulerAngles = localAngle;
            }

            if (Input.GetKey(KeyCode.A))
            {
                transform.position -= transform.TransformDirection(Vector3.back) * 3f * Time.deltaTime;
            }
            if (Input.GetKeyDown(KeyCode.A))
            {
                Vector3 localAngle = myTransform.localEulerAngles;
                localAngle.y = 90;

                myTransform.localEulerAngles = localAngle;
            }

            if (Input.GetKey(KeyCode.W))
            {
                transform.position -= transform.TransformDirection(Vector3.back) * 3f * Time.deltaTime;
            }
            if (Input.GetKeyDown(KeyCode.W))
            {
                Vector3 localAngle = myTransform.localEulerAngles;
                localAngle.y = 180;

                myTransform.localEulerAngles = localAngle;
            }

            if (Input.GetKey(KeyCode.S))
            {
                transform.position -= transform.TransformDirection(Vector3.back) * 3f * Time.deltaTime;
            }
            if (Input.GetKeyDown(KeyCode.S))
            {
                Vector3 localAngle = myTransform.localEulerAngles;
                localAngle.y = 0;

                myTransform.localEulerAngles = localAngle;
            }
        }


        //カメラの座標が（20,6,0）の時
        if (target.transform.position.z == 0)
        {
            if (target.transform.position.x == 20)
            {
                if (Input.GetKey(KeyCode.D))
                {
                    transform.position -= transform.TransformDirection(Vector3.back) * 3f * Time.deltaTime;
                }
                if (Input.GetKeyDown(KeyCode.D))
                {
                    Vector3 localAngle = myTransform.localEulerAngles;
                    localAngle.y = 0;

                    myTransform.localEulerAngles = localAngle;
                }

                if (Input.GetKey(KeyCode.A))
                {
                    transform.position -= transform.TransformDirection(Vector3.back) * 3f * Time.deltaTime;
                }
                if (Input.GetKeyDown(KeyCode.A))
                {
                    Vector3 localAngle = myTransform.localEulerAngles;
                    localAngle.y = 180;

                    myTransform.localEulerAngles = localAngle;
                }

                if (Input.GetKey(KeyCode.W))
                {
                    transform.position -= transform.TransformDirection(Vector3.back) * 3f * Time.deltaTime;
                }
                if (Input.GetKeyDown(KeyCode.W))
                {
                    Vector3 localAngle = myTransform.localEulerAngles;
                    localAngle.y = -90;

                    myTransform.localEulerAngles = localAngle;
                }

                if (Input.GetKey(KeyCode.S))
                {
                    transform.position -= transform.TransformDirection(Vector3.back) * 3f * Time.deltaTime;
                }
                if (Input.GetKeyDown(KeyCode.S))
                {
                    Vector3 localAngle = myTransform.localEulerAngles;
                    localAngle.y = 90;

                    myTransform.localEulerAngles = localAngle;
                }
            }
        }

        //棚の前でEnterを押すとシーンの移動
        if (transform.position.z < -3)
        {
            if (transform.position.z > -7)
            {
                if (transform.position.x < 3)
                {
                    if (transform.position.x > 0)
                    {
                        if (Input.GetKeyDown(KeyCode.Return))
                        {
                            SceneManager.LoadScene("Tana");
                        }
                    }
                }
            }
        }
       
        //ベッドの前でEnterを押すと
    }
}
