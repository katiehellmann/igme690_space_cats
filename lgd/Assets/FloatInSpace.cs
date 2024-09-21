using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class NewBehaviourScript : MonoBehaviour
{
    public float FloatStrenght;
    public float RandomRotationStrenght;

    [SerializeField] Rigidbody m_rb;

    void FixedUpdate()
    {
        m_rb.AddForce(Vector3.up * FloatStrenght);
        m_rb.transform.Rotate(RandomRotationStrenght, RandomRotationStrenght, RandomRotationStrenght);
      


    }
    private void Update()
    {
        
    }
}
