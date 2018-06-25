package com.github.bayupaoh.smartlamp

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import com.google.firebase.database.DatabaseReference
import com.google.firebase.database.FirebaseDatabase
import com.google.firebase.database.DatabaseError
import com.google.firebase.database.DataSnapshot
import com.google.firebase.database.ValueEventListener
import kotlinx.android.synthetic.main.activity_main.*


class MainActivity : AppCompatActivity() {

    var database: FirebaseDatabase? = null
    var myRef: DatabaseReference? = null
    var value: Int? = 0

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        database = FirebaseDatabase.getInstance()
        myRef = database?.getReference("lampuOn")


        myRef?.addValueEventListener(object : ValueEventListener {
            override fun onDataChange(dataSnapshot: DataSnapshot) {
                // This method is called once with the initial value and again
                // whenever data at this location is updated.
                value = dataSnapshot.getValue(Int::class.java)
                if (value != 0) {
                    mainStatus.text = "Lampu Nyala"
                    mainBtnAction.text = "Matikan Lampu"
                } else {
                    mainStatus.text = "Lampu Mati"
                    mainBtnAction.text = "Nyalakan Lampu"
                }
            }

            override fun onCancelled(error: DatabaseError) {
                mainStatus.text = "Error : "+error?.message
            }
        })

        mainBtnAction.setOnClickListener { view ->
            if (value == 0) {
                myRef?.setValue(1)
            }else {
                myRef?.setValue(0)
            }
        }
    }
}
