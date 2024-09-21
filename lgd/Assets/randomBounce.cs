using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RandomBounce : MonoBehaviour
{
    Rigidbody _rb;
    void Start()
    {
        _rb = GetComponent<Rigidbody>();

        // Increase max angular velocity or we won't see much spin.
        _rb.maxAngularVelocity = 500;
       
       
       StartCoroutine(ChangeRotation());
    }

    private void FixedUpdate()
    {
        _rb.useGravity = false;
        new WaitForSeconds(.5f);
        _rb.useGravity = true;
        new WaitForSeconds(1);
    }

    private IEnumerator ChangeRotation()
    {
        while (true)
        {
            _rb.AddTorque(new Vector3(10 * UnityEngine.Random.Range(0, .4f), UnityEngine.Random.Range(0, .4f), UnityEngine.Random.Range(0, .4f)), ForceMode.Impulse);
            yield return new WaitForSeconds(1);
        }
    }
}
